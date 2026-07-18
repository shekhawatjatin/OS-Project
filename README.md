# OS-Project
# 🖥️ CPU Scheduling Simulator

## 📌 Overview

This project is a **CPU Scheduling Simulator** developed in C++ that demonstrates how different scheduling algorithms work in an operating system.
It calculates and compares **Waiting Time (WT)** and **Turnaround Time (TAT)** for multiple processes and displays a **Gantt Chart** for visualization.

---

## 🎯 Objectives

* To understand different CPU scheduling algorithms
* To compare their performance
* To simulate real-time process execution
* To calculate scheduling metrics like WT and TAT

---

## ⚙️ Features

✔ First Come First Serve (FCFS)
✔ Shortest Job First (SJF - Non Preemptive)
✔ Shortest Remaining Time First (SRTF - Preemptive)
✔ Round Robin (RR) Scheduling
✔ Gantt Chart with timeline
✔ Calculation of:

* Completion Time (CT)
* Waiting Time (WT)
* Turnaround Time (TAT)
  ✔ Average WT and TAT
  ✔ Handles edge cases (idle CPU, same arrival time)

---

## 🧠 Algorithms Implemented

### 1. FCFS (First Come First Serve)

* Processes are executed in the order of arrival.

### 2. SJF (Shortest Job First)

* Process with the smallest burst time is executed first.

### 3. SRTF (Preemptive SJF)

* The process with the shortest remaining time is selected at every time unit.

### 4. Round Robin

* Each process is given a fixed time quantum in a cyclic manner.

---

## 📥 Input

* Number of processes
* Arrival Time (AT)
* Burst Time (BT)
* Time Quantum (for Round Robin)

---

## 📤 Output

* Gantt Chart
* Completion Time (CT)
* Waiting Time (WT)
* Turnaround Time (TAT)
* Average WT and TAT

---

## 🧮 Formulas Used

* Turnaround Time (TAT) = Completion Time - Arrival Time
* Waiting Time (WT) = Turnaround Time - Burst Time

---

## 💻 How to Run

### 🔹 Using VS Code

1. Open the project folder in VS Code
2. Open terminal (`Ctrl + ``)
3. Compile:

   ```bash
   g++ cpu.cpp -o cpu
   ```
4. Run:

   ```bash
   cpu
   ```

---

## 📊 Sample Input

```
Enter number of processes: 3  
P1: 0 5  
P2: 1 3  
P3: 2 8  
Quantum: 2  
```

---

## 🏆 Advantages

* Easy to understand implementation
* Covers both preemptive and non-preemptive algorithms
* Helps in learning OS scheduling concepts
* Useful for academic purposes

---

## ⚠️ Limitations

* Console-based (no GUI)
* Limited to basic scheduling algorithms
* Does not simulate real OS environment

---

## 🚀 Future Improvements

* Add graphical user interface (GUI)
* Add priority scheduling
* Export results to file
* Visual animation of scheduling

---



## 📚 Conclusion

This project provides a clear understanding of how CPU scheduling works and how different algorithms affect process performance. It is a useful educational tool for students studying Operating Systems.

---
