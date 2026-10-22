# Tejas Robot - Git Workflow

## Branching Strategy
We use **feature branching**. Never commit directly to `main`.

## Branch Naming
| Type | Format | Example |
|---|---|---|
| Feature | `feature/<name>-<task>` | `feature/member3-esp32-firmware` |
| Bug Fix | `fix/<issue-desc>` | `fix/motor-wiring-issue` |
| Documentation | `docs/<name>` | `docs/member7-report` |
| Testing | `test/<module>` | `test/slam-integration` |

## Daily Workflow
1. **Pull latest** - `git checkout main && git pull origin main`
2. **Create branch** - `git checkout -b feature/your-branch-name`
3. **Work & commit** - Make changes, commit often with clear messages
4. **Push** - `git push -u origin feature/your-branch-name`
5. **Create Pull Request** - Open PR on GitHub to merge into `main`
6. **Review** - Get reviewed by Team Lead (Member 1)
7. **Merge** - After approval, merge via GitHub (Squash & Merge recommended)

## Commit Message Format
```
<type>: <short description>

Example:
feat: add ESP32 sensor data reader
fix: correct UART baudrate
docs: update wiring diagram
chore: add test files
```

## Rules
- Pull before starting work
- Commit small, logical changes
- Don't push broken code
- Always create PR for merging to main
- Member 7 reviews docs, Member 1 approves merges

