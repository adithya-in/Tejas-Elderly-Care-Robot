# GitHub for Beginners - Tejas Project

This guide is made specifically for the Tejas team. Follow step by step.

## What is GitHub?
GitHub is like Google Drive for code. It lets all 7 of you work on the same project together without overwriting each other's files.

## Setup (Do this once)

### 1. Install Git
- **Mac**: Already have it or install from [git-scm.com](https://git-scm.com)
- **Windows**: Download Git from [git-scm.com](https://git-scm.com)

### 2. Configure Git (Only first time)
Open Terminal/Command Prompt and run:
```bash
git config --global user.name "YourFullName"
git config --global user.email "your-email@example.com"
```

### 3. Clone the Repo
This downloads the project to your laptop
```bash
cd Desktop
git clone https://github.com/adithya-in/Tejas-Elderly-Care-Robot.git
cd Tejas-Elderly-Care-Robot
```

## Daily Workflow (Follow every time)

### Step 1: Get latest code
Before you start working, always get updated code from others
```bash
git checkout main
git pull origin main
```

### Step 2: Create your own branch
Make a separate copy for your work
```bash
git checkout -b feature/memberX-yourtask
# Example: git checkout -b feature/member3-esp32-code
```

### Step 3: Do your work
Add your files in the correct folder:
- Member 2 (Hardware) → `hardware/`
- Member 3 (Embedded) → `embedded/`
- Member 4 (Software & AI) → `software/` or `ai/`
- Member 5 (Robotics & SLAM) → `ros2/slam/`
- Member 6 (Design & Fabrication) → `fabrication/`
- Member 7 (Documentation & Testing) → `docs/` or `tests/`
- Member 1 (Lead) → Can work anywhere, reviews all

### Step 4: Save your changes
```bash
git add .
git commit -m "feat: brief description of what you did"
# Example: git commit -m "feat: added ESP32 sensor code"
```

### Step 5: Upload your branch
```bash
git push -u origin feature/memberX-yourtask
```

### Step 6: Create Pull Request (PR)
1. Go to [Tejas Repo](https://github.com/adithya-in/Tejas-Elderly-Care-Robot)
2. You'll see "Compare & pull request" button → Click it
3. Add title & description of what you did
4. Click "Create pull request"
5. Tell Member 1 (Team Lead) to review

### Step 7: Merge
After Member 1 approves, they will merge it. Then next day do Step 1 again.

## Simple Rules
- **NEVER** edit directly on `main` branch
- **ALWAYS** create a new branch for your work
- **ALWAYS** pull before starting
- **ALWAYS** create PR, don't push to main
- **Keep commits small** - Do this 2-3 times a day

## Common Commands Cheat Sheet
```bash
git status                # See what files changed
git branch                # See which branch you're on
git log --oneline -5      # See recent commits
git checkout main         # Switch to main branch
```

## Help
If stuck, ask Member 1 or Member 7. Don't delete anything randomly!
