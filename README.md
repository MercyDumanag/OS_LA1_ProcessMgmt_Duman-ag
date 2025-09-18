# OS_LA1_ProcessMgmt_Duman-ag Deliverables
## This repository contains all source files and documentation for OS Laboratory Activity 1 – Process Management.

### Contents

**src/**– Source code files (.c) for each task.

**Screenshots/** – Screenshots of serial outputs and PowerShell process listings.

**README.md** – This file with build instructions and task notes.

## 🔧 Build Instructions Using VS Code (with MinGW)

1. **Install MinGW-w64** and add it to your system PATH.

2. **Open VS Code** and ensure the C/C++ extension is installed.

3. **Open a terminal** in the `src/` directory.

4. **Compile the source files** using:
   ```bash
   gcc child_echo.c -o child_echo.exe
   gcc create_basic.c -o create_basic.exe
   gcc create_two_children.c -o create_two_children.exe
   gcc replace_sim.c -o replace_sim.exe 
   ```

# **Sample Outputs**

## 🖼️ Screenshots

### Task A Output
![Task A Output](Screenshots/Task%20A.png)

### Task B Output
![Task B Output](Screenshots/Task%20B.png)

### Task C Output
![Task C Output](Screenshots/Task%20C.png)

### PowerShell Termination – Normal Exit
![Normal Exit 1](Screenshots/Task%20D%20Normal%20Exit.png)  
![Normal Exit 2](Screenshots/Task%20D%20Normal%20Exit2.png)

### PowerShell Termination – Forced Exit
![Forced Exit 1](Screenshots/Task%20D.png)  
![Forced Exit 2](Screenshots/Task%20D2.png)


## 📝 Notes on Tasks

### **Task A – Creating a Single Child**
- Successfully created a child process using `CreateProcess()`.
- Verified parent and child PIDs.

### **Task B – Creating Two Children**
- Created two child processes and handled their execution.
- Demonstrated both normal termination and forced termination.

### **Task C – Simulating exec()**
- Parent spawns a new process (`cmd /c dir`) and waits for it to finish.
- Exits with the same exit code as the spawned process.
- Parent ends quickly after child completes, simulating `exec()` behavior.

### **Task D – Process Management in PowerShell**
- Used `Get-Process child_echo` to list running child processes.
- Used `Stop-Process -Id <PID>` to terminate processes.
- Observed difference between normal termination (clean exit) vs forced termination.

