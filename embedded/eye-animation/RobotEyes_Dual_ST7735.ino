/*
 * Tejas Elderly Care Robot - Dual Eye Animation
 * ESP8266 + two 1.8" ST7735 TFT displays (160x128 landscape)
 *
 * Wiring:
 *   SCK  -> D5 / GPIO14  (both displays)
 *   MOSI -> D7 / GPIO13  (both displays)
 *   A0/DC -> D1 / GPIO5  (shared by both displays)
 *   Left  CS -> D8 / GPIO15
 *   Right CS -> D0 / GPIO16
 *   RST of both -> 3.3V (software reset is used)
 *   VCC, LED/BL -> 3.3V, GND -> GND
 *
 * Libraries: Adafruit GFX Library, Adafruit ST7735 and ST7789 Library
 */

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "RoboEyesTFT.h"

#define PIN_SCK   14
#define PIN_MOSI  13
#define PIN_CS_L  15
#define PIN_CS_R  16
#define PIN_DC     5

const int SCREEN_W = 160;
const int SCREEN_H = 128;
const int EYE_W = 90;
const int EYE_H = 110;
const int EYE_R = 26;

Adafruit_ST7735 tftL(PIN_CS_L, PIN_DC, -1);
Adafruit_ST7735 tftR(PIN_CS_R, PIN_DC, -1);

class Canvas8 : public GFXcanvas8 {
public:
  bool mirror = false;

  Canvas8(int16_t w, int16_t h) : GFXcanvas8(w, h) {}

  void fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color) {
    if (mirror) {
      GFXcanvas8::fillRoundRect(width() - x - w, y, w, h, r, color);
    } else {
      GFXcanvas8::fillRoundRect(x, y, w, h, r, color);
    }
  }

  void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
    if (mirror) {
      GFXcanvas8::fillTriangle(width() - 1 - x0, y0, width() - 1 - x1, y1, width() - 1 - x2, y2, color);
    } else {
      GFXcanvas8::fillTriangle(x0, y0, x1, y1, x2, y2, color);
    }
  }
};

Canvas8 canvas(SCREEN_W, SCREEN_H);
RoboEyesTFT<Canvas8> eyeL(canvas);
RoboEyesTFT<Canvas8> eyeR(canvas);

int eyeX = (SCREEN_W - EYE_W) / 2;
int eyeY = (SCREEN_H - EYE_H) / 2;
int eyeDir = 1;

unsigned long frameTimer = 0;
unsigned long nextBlinkAt = 0;

void pushCanvas(Adafruit_ST7735 &tft, Canvas8 &cv, uint16_t fg, uint16_t bg) {
  uint8_t *buf = cv.getBuffer();
  uint16_t line[SCREEN_W];
  tft.startWrite();
  tft.setAddrWindow(0, 0, SCREEN_W, SCREEN_H);
  for (int y = 0; y < SCREEN_H; y++) {
    int off = y * SCREEN_W;
    for (int x = 0; x < SCREEN_W; x++) {
      line[x] = buf[off + x] ? fg : bg;
    }
    tft.writePixels(line, SCREEN_W);
  }
  tft.endWrite();
}

void applyEyePositions() {
  eyeL.eyeLxNext = eyeX;
  eyeL.eyeLyNext = eyeY;
  eyeR.eyeLxNext = (SCREEN_W - EYE_W) - eyeX;
  eyeR.eyeLyNext = eyeY;
}

void setup() {
  Serial.begin(115200);

  tftL.initR(INITR_BLACKTAB);
  tftL.setRotation(1);
  tftL.setSPISpeed(27000000);
  tftL.fillScreen(ST77XX_BLACK);

  tftR.initR(INITR_BLACKTAB);
  tftR.setRotation(1);
  tftR.setSPISpeed(27000000);
  tftR.fillScreen(ST77XX_BLACK);

  if (!canvas.getBuffer()) {
    Serial.println("Canvas allocation failed");
    while (1) {
      delay(1000);
    }
  }

  eyeL.begin(SCREEN_W, SCREEN_H, 25);
  eyeR.begin(SCREEN_W, SCREEN_H, 25);

  eyeL.setDisplayColors(ST77XX_BLACK, ST77XX_BLUE);
  eyeR.setDisplayColors(ST77XX_BLACK, ST77XX_BLUE);

  eyeL.setWidth(EYE_W, EYE_W);
  eyeR.setWidth(EYE_W, EYE_W);
  eyeL.setHeight(EYE_H, EYE_H);
  eyeR.setHeight(EYE_H, EYE_H);
  eyeL.setBorderradius(EYE_R, EYE_R);
  eyeR.setBorderradius(EYE_R, EYE_R);
  eyeL.setSpacebetween(0);
  eyeR.setSpacebetween(0);

  eyeL.setCyclops(ON);
  eyeR.setCyclops(ON);
  eyeR.mirrorX = true;

  eyeL.eyeLwidthCurrent = EYE_W;
  eyeR.eyeLwidthCurrent = EYE_W;
  eyeL.eyeLborderRadiusCurrent = EYE_R;
  eyeR.eyeLborderRadiusCurrent = EYE_R;

  eyeL.centerSingleEye();
  eyeR.centerSingleEye();
  applyEyePositions();

  nextBlinkAt = millis() + 3000;
}

void loop() {
  if (millis() - frameTimer >= 40) {
    frameTimer = millis();

    eyeX += eyeDir;
    if (eyeX <= 0) {
      eyeX = 0;
      eyeDir = 1;
    }
    if (eyeX >= SCREEN_W - EYE_W) {
      eyeX = SCREEN_W - EYE_W;
      eyeDir = -1;
    }
    applyEyePositions();

    if (millis() >= nextBlinkAt) {
      eyeL.blink();
      eyeR.blink();
      nextBlinkAt = millis() + random(2500, 5000);
    }

    canvas.mirror = false;
    eyeL.drawEyes();
    pushCanvas(tftL, canvas, ST77XX_BLUE, ST77XX_BLACK);

    canvas.mirror = true;
    eyeR.drawEyes();
    pushCanvas(tftR, canvas, ST77XX_BLUE, ST77XX_BLACK);
  }
}
