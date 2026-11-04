/*
 * Tejas Elderly Care Robot - Dual Eye Animation
 * ESP8266 + two 1.8" ST7735 TFT displays (128x160)
 *
 * Wiring:
 *   SCK  -> D5 / GPIO14  (both displays)
 *   MOSI -> D7 / GPIO13  (both displays)
 *   Left  CS -> D8 / GPIO15, DC -> D1 / GPIO5
 *   Right CS -> D0 / GPIO16, DC -> D2 / GPIO4
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
#define PIN_DC_L   5
#define PIN_CS_R  16
#define PIN_DC_R   4

const int W = 128;
const int H = 160;
const int EYE_W = 90;
const int EYE_H = 110;
const int EYE_R = 26;

Adafruit_ST7735 tftL(PIN_CS_L, PIN_DC_L, -1);

class MirrorST7735 : public Adafruit_ST7735 {
public:
  MirrorST7735(int16_t cs, int16_t dc, int16_t rst) : Adafruit_ST7735(cs, dc, rst) {}

  void fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color) {
    Adafruit_ST7735::fillRoundRect(width() - x - w, y, w, h, r, color);
  }

  void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
    Adafruit_ST7735::fillTriangle(width() - 1 - x0, y0, width() - 1 - x1, y1, width() - 1 - x2, y2, color);
  }
};

MirrorST7735 tftR(PIN_CS_R, PIN_DC_R, -1);

RoboEyesTFT<Adafruit_ST7735> eyeL(tftL);
RoboEyesTFT<MirrorST7735> eyeR(tftR);

int eyeX = (W - EYE_W) / 2;
int eyeY = (H - EYE_H) / 2;

unsigned long frameTimer = 0;
unsigned long nextBlinkAt = 0;
unsigned long nextIdleAt = 0;
unsigned long nextMoodAt = 0;
unsigned long nextSpecialAt = 0;
uint8_t moodIndex = 0;
const uint8_t moods[4] = {DEFAULT, HAPPY, ANGRY, TIRED};

void applyEyePositions() {
  eyeL.eyeLxNext = eyeX;
  eyeL.eyeLyNext = eyeY;
  eyeR.eyeLxNext = (W - EYE_W) - eyeX;
  eyeR.eyeLyNext = eyeY;
}

void lookAt(int x, int y) {
  eyeX = constrain(x, 0, W - EYE_W);
  eyeY = constrain(y, 0, H - EYE_H);
  applyEyePositions();
}

void setMoodAll(uint8_t mood) {
  eyeL.setMood(mood);
  eyeR.setMood(mood);
}

void setup() {
  Serial.begin(115200);

  tftL.initR(INITR_BLACKTAB);
  tftL.setRotation(0);
  tftL.setSPISpeed(40000000);
  tftL.fillScreen(ST77XX_BLACK);

  tftR.initR(INITR_BLACKTAB);
  tftR.setRotation(0);
  tftR.setSPISpeed(40000000);
  tftR.fillScreen(ST77XX_BLACK);

  eyeL.begin(W, H, 25);
  eyeR.begin(W, H, 25);

  eyeL.setDisplayColors(ST77XX_BLACK, ST77XX_WHITE);
  eyeR.setDisplayColors(ST77XX_BLACK, ST77XX_WHITE);

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
  nextIdleAt = millis() + 1500;
  nextMoodAt = millis() + 6000;
  nextSpecialAt = millis() + 9000;
}

void updateAnimations() {
  unsigned long now = millis();

  if (now >= nextBlinkAt) {
    eyeL.blink();
    eyeR.blink();
    nextBlinkAt = now + random(2000, 6000);
  }

  if (now >= nextIdleAt) {
    eyeX = random(0, W - EYE_W + 1);
    eyeY = random(0, H - EYE_H + 1);
    applyEyePositions();
    nextIdleAt = now + random(1500, 5000);
  }

  if (now >= nextMoodAt) {
    moodIndex = (moodIndex + 1) % 4;
    setMoodAll(moods[moodIndex]);
    nextMoodAt = now + 6000;
  }

  if (now >= nextSpecialAt) {
    if (random(2) == 0) {
      eyeL.anim_laugh();
      eyeR.anim_laugh();
    } else {
      eyeL.anim_confused();
      eyeR.anim_confused();
    }
    nextSpecialAt = now + 9000;
  }
}

void loop() {
  updateAnimations();

  if (millis() - frameTimer >= 40) {
    eyeL.drawEyes();
    eyeR.drawEyes();
    frameTimer = millis();
  }
}
