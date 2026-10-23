# JOB ASSIGNMENT FOR 7 MEMBERS - TEJAS ROBOT
**Duration: 1.5 Months (6 Weeks) | Phase 1: Brain + Senses**

---

## MEMBER 1 - TEAM LEAD & SYSTEM ARCHITECT

**Goal:** Oversee, coordinate and ensure proper integration of all modules.

### Timeline

| Week | Task | Details | Status |
|---|---|---|---|
| **Week 1** | System Planning | Create system block diagram, define connections between modules, assign clear tasks | Pending |
| **Week 2** | Coordination | Check each member's progress, solve blockers, maintain GitHub PR reviews | Pending |
| **Week 3** | Integration Planning | Plan how ESP32, Pi5, ROS2, AI connect together, prepare wiring map | Pending |
| **Week 4** | Mid Review | Review all modules, fix integration conflicts, update plan | Pending |
| **Week 5** | Integration Start | Begin combining modules, test communication between systems | Pending |
| **Week 6** | Final Integration & Demo Prep | Full system check, demo run, verify all requirements met | Pending |

**Deliverables:** System Architecture Diagram, Integration Plan, Weekly Review Reports

---

## MEMBER 2 - HARDWARE & ELECTRONICS

**Goal:** Handle all wiring, power and hardware connections.

### Timeline

| Week | Task | Details | Status |
|---|---|---|---|
| **Week 1** | Component Study | Study BOM for Phase 1, check pinouts of Pi5, ESP32, sensors | Pending |
| **Week 2** | Power Design | Plan 5V/3.3V distribution, test PSU, breadboard layout | Pending |
| **Week 3** | Wiring | Wire Pi5, ESP32, mmWave, IMU, Camera on breadboard neatly | Pending |
| **Week 4** | Connections & Routing | Organize cables, check loose connections, label wires | Pending |
| **Week 5** | Power Testing | Test stable voltage, avoid shorts, check current flow | Pending |
| **Week 6** | Final Wiring Check | Clean up wiring for demo, prepare hardware report | Pending |

**Deliverables:** Wiring Diagram, Breadboard Prototype, Hardware Layout

**Folder:** `hardware/`

---

## MEMBER 3 - EMBEDDED SYSTEMS (ESP32)

**Goal:** Program ESP32 to read sensors and communicate with Raspberry Pi.

### Timeline

| Week | Task | Details | Status |
|---|---|---|---|
| **Week 1** | Setup | Install Arduino IDE/PlatformIO, add ESP32 board, test blink | Pending |
| **Week 2** | MPU6050 Interfacing | Code to read accelerometer/gyroscope, test values on serial monitor | Pending |
| **Week 3** | mmWave Interfacing | Interface Seeed MR24HPC1, read presence/motion data | Pending |
| **Week 4** | UART Communication | Send sensor data from ESP32 to Raspberry Pi via Serial/UART | Pending |
| **Week 5** | Fall Detection Logic | Add basic fall detection logic using sensor data | Pending |
| **Week 6** | Testing & Integration | Test with Pi, debug, finalize firmware | Pending |

**Deliverables:** ESP32 Firmware (.ino/.cpp), Sensor Test Logs, UART Protocol Doc

**Folder:** `embedded/`

---

## MEMBER 4 - SOFTWARE & AI (CHATBOT)

**Goal:** Build local AI chatbot for elderly interaction using Ollama.

### Timeline

| Week | Task | Details | Status |
|---|---|---|---|
| **Week 1** | Environment Setup | Prepare Pi OS plan, research Ollama installation | Pending |
| **Week 2** | Ollama Setup | Install Ollama on Pi/Laptop, pull Llama 3.1 model | Pending |
| **Week 3** | Chatbot Core | Create Python script for chatbot, test basic Q&A | Pending |
| **Week 4** | Elderly Care Features | Add medication reminder, SOS keywords, polite responses | Pending |
| **Week 5** | Voice I/O | Add mic input + speaker output (basic version) | Pending |
| **Week 6** | API & Integration | Create Flask API to connect with other modules, test with team | Pending |

**Deliverables:** Chatbot Code, Flask API, Prompt File, Demo Video Script

**Folder:** `ai/` & `software/`

---

## MEMBER 5 - ROBOTICS & SLAM

**Goal:** Implement ROS2 + RTAB-Map for mapping and navigation.

### Timeline

| Week | Task | Details | Status |
|---|---|---|---|
| **Week 1** | ROS2 Basics | Learn/install ROS2 Jazzy concepts, setup workspace | Pending |
| **Week 2** | Camera Setup | Configure RPi Camera v3, test with ROS2 image view | Pending |
| **Week 3** | RTAB-Map Setup | Install rtabmap_ros, configure for monocular/stereo | Pending |
| **Week 4** | SLAM Testing | Run RTAB-Map in a room, generate 2D map | Pending |
| **Week 5** | Sensor Fusion | Try to fuse mmWave data with camera for better detection | Pending |
| **Week 6** | Final Map & Integration | Save map, test with Pi, integrate with Team Lead | Pending |

**Deliverables:** ROS2 Workspace, Launch Files, SLAM Map, Setup Guide

**Folder:** `ros2/slam/`

---

## MEMBER 6 - DESIGN & FABRICATION

**Goal:** Design mounts, enclosures and fabricate/assemble structure.

### Timeline

| Week | Task | Details | Status |
|---|---|---|---|
| **Week 1** | Study Design | Study Axon CAD, decide what to adapt for Tejas | Pending |
| **Week 2** | CAD Modelling | Design simple mounts for Pi5, ESP32, Camera, mmWave | Pending |
| **Week 3** | Fabrication Prep | Create/modify parts for fabrication (cardboard/mockup first) | Pending |
| **Week 4** | Mounting | Fit all components in mockup, check spacing/cable routing | Pending |
| **Week 5** | Assembly | Fix mounts, improve layout, make sturdy base | Pending |
| **Week 6** | Final Assembly | Complete prototype structure, present to team for integration | Pending |

**Deliverables:** CAD Files, Fabrication Sketches, Assembled Structure, Mounting Guide

**Folder:** `fabrication/`

---

## MEMBER 7 - DOCUMENTATION & TESTING

**Goal:** Document everything, test all modules and ensure quality.

### Timeline

| Week | Task | Details | Status |
|---|---|---|---|
| **Week 1** | Documentation Setup | Create folder structure docs, maintain work log template | Pending |
| **Week 2** | Collect Data | Get updates from all members, start compiling report | Pending |
| **Week 3** | Testing Plan | Create test checklist for each module (Hardware, ESP32, AI, SLAM) | Pending |
| **Week 4** | Module Testing | Test each module separately with team members | Pending |
| **Week 5** | Integration Testing | Test full system together, log bugs & report to Team Lead | Pending |
| **Week 6** | Final Report & Demo Docs | Complete Phase 1 report, user guide, test results, photos | Pending |

**Deliverables:** Phase 1 Report, Test Report, User Guide, GitHub Updates, Demo Documentation

**Folder:** `docs/` & `tests/`

---

## OVERALL TIMELINE SUMMARY

| Week | Focus | Target |
|---|---|---|
| **Week 1** | Setup & Planning | All members set up GitHub, start their tasks |
| **Week 2** | Individual Work | Core modules in progress |
| **Week 3** | Development | Major parts working individually |
| **Week 4** | Mid Review | All modules tested individually |
| **Week 5** | Integration | Combine modules together |
| **Week 6** | Testing & Demo | Final prototype ready for review |

---

## IMPORTANT INSTRUCTIONS

- **Use GitHub daily** - Follow the GitHub for Beginners guide
- **Update weekly** - Post progress in team group / update on GitHub
- **Focus on Phase 1 only** - Brain + Senses. Don't jump to full body yet
- **Teamwork first** - Help each other, especially during integration
- **Document as you go** - Member 7 will need updates
- **Ask before guessing** - Clear doubts with Team Lead (Member 1)
