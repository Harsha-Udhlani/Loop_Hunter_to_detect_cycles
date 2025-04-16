# 🔁 LoopHunter — Detect Cycles in Graphs and Linked Lists

**LoopHunter** is a C++ console-based project that detects cycles using various algorithms in both:

- **Graphs** (Directed and Undirected)
- **Linked Lists**

The system features a menu-driven interface allowing users to choose the type of structure and algorithm, and view time and space complexities. It is designed for both educational and practical use.

---

## 🧠 Features

- Detect cycles in **Linked Lists** using:
  - Hashing (Set method)
  - Slow-Fast Pointer (Floyd’s Cycle Detection)

- Detect cycles in **Graphs** using:
  - BFS (Kahn’s Algorithm for Directed Graphs)
  - DFS (for both Directed and Undirected Graphs)

- Displays:
  - Time and space complexity of each method
  - User-friendly menu interface
  - Optional visualization-friendly structure (for future upgrades)

---

## 🚀 How to Push Code to GitHub (Main Branch)

This guide helps you push your local project to a GitHub repository on the `main` branch.

---

## ✅ Step-by-Step Commands

### 1. Initialize Git (only once)
```bash
git init
```

### 2. Rename the branch to `main`
```bash
git branch -M main
```

### 3. Add a remote repository
```bash
git remote add origin https://github.com/Harsha-Udhlani/Loop_Hunter_to_detect_cycles.git
```

### 4. Add files to staging
```bash
git add .
```

### 5. Commit your changes
```bash
git commit -m "Initial commit"
```

---

## 🚧 If You See This Error:
```
error: failed to push some refs...
hint: Updates were rejected because the remote contains work that you do not have locally.
```

### 🛠️ Fix It:

Run this command to pull remote files and merge histories:
```bash
git pull origin main --allow-unrelated-histories
```

Then push again:
```bash
git push -u origin main
```

---

## ✅ You're Done!

Your project is now successfully pushed to the `main` branch on GitHub 🎉
