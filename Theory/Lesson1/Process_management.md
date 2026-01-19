# 📝 Detailed Notes — OS & Process Management (14 Sept 2025)

---

## 1. Operating System Basics

### What is an OS?

- An **Operating System (OS)** is system software that acts as a **bridge between hardware and user programs**.
- It hides low-level hardware details and provides a convenient interface for applications.
- Without an OS, each program would have to directly manage CPU, memory, I/O devices — which is impractical.

### Key Roles of OS:

1. **Resource Manager**

   - Allocates and deallocates CPU, memory, I/O devices, and storage.
   - Ensures fairness and efficiency.

2. **Process Manager**

   - Creates, schedules, and terminates processes.
   - Handles synchronization, communication, and deadlock issues.

3. **Memory Manager**

   - Keeps track of memory usage.
   - Allocates memory to processes and reclaims it when no longer needed.

4. **File System Manager**

   - Provides a structured way to store and access data on disks.
   - Handles permissions, hierarchy, and metadata.

5. **I/O Manager**

   - Manages input/output devices via drivers.
   - Provides buffering, caching, and spooling.

6. **Security and Protection**

   - Enforces boundaries between processes.
   - Prevents unauthorized access.

👉 **Brainstorm analogy:** Think of OS as a **traffic controller** at a busy junction — deciding who goes when, avoiding collisions, and keeping traffic flowing.

---

## 2. Modes of Execution: Kernel Mode vs User Mode

- Modern CPUs support at least **two modes**:

  1. **User Mode**

     - Where normal applications run.
     - Restricted: cannot directly access hardware or sensitive instructions.
     - Needs to request services from kernel via **system calls**.

  2. **Kernel Mode**

     - Privileged mode where the OS core runs.
     - Full access to hardware, memory, and instructions.
     - Executes tasks like process scheduling, device control.

👉 This separation prevents buggy/malicious user programs from crashing the entire system.

---

## 3. Program vs Process

- **Program**:

  - A **passive set of instructions** stored on disk (e.g., `hello.c`, `hello.exe`).
  - Doesn’t do anything by itself.

- **Process**:

  - An **active execution instance** of a program.
  - When the OS loads a program into memory and assigns it resources, it becomes a process.
  - Identified by a **PID (Process ID)**.

👉 **Analogy:** Program = recipe written in a cookbook. Process = actually cooking the dish following that recipe.

---

## 4. Process Lifecycle (from creation to termination)

1. **Creation**

   - Triggered by user (`./hello`) or another process (`fork()` in Unix).
   - OS allocates a **PID** and sets up memory (code, data, stack).

2. **Ready State**

   - Process waits in the ready queue for CPU time.

3. **Running**

   - Scheduler picks process, CPU executes its instructions.

4. **Waiting/Blocked**

   - If process needs I/O (e.g., reading a file), it waits for the operation to complete.

5. **Termination**

   - Process finishes execution or is killed.
   - OS deallocates its resources and clears PCB.

---

## 5. Process Control Block (PCB)

- A **PCB** is a data structure used by the OS to keep track of a process.
- Acts like the process’s **identity card + notebook**.

**Contents of PCB:**

- **Identification**: PID, PPID (parent process ID).
- **CPU State**: program counter, registers, stack pointer.
- **Memory Info**: base/limit registers, page tables.
- **Scheduling Info**: priority, process state (ready, waiting, running).
- **I/O Info**: open files, pending signals.

👉 Without a PCB, the OS wouldn’t know:

- Which resources belong to which process.
- Where to resume execution after a context switch.

---

## 6. Context Switching

- **Context switch** = OS suspends one process and resumes another.
- Steps:

  1. Save the **current process’s state** into its PCB (program counter, registers).
  2. Load the **next process’s state** from its PCB.
  3. CPU continues executing the new process.

👉 Without PCB, resuming would be impossible — processes would restart from the beginning.

👉 Analogy: Like putting a bookmark in one book before starting another, so you can come back later without losing your place.

---

## 7. PID (Process ID)

- Every process in the system is assigned a unique **PID**.
- Helps OS and users identify and manage processes.
- Example: `kill 12345` kills process with PID 12345.

---

## 8. Code Exercises Today

### 8.1 `hello.c`

```c
#include <stdio.h>

int main() {
    printf("Hello, world!\n");
    return 0;
}
```

- Simple program → prints message then exits.
- It runs and terminates so quickly that you won’t see it in `ps`.

---

### 8.2 `getpid.c`

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("My process ID is: %d\n", getpid());
    while (1);  // infinite loop keeps process alive
    return 0;
}
```

- **getpid()** returns PID of the process.
- Adding `while(1);` keeps process alive so you can observe it.

Compile & run:

```bash
gcc getpid.c -o getpid
./getpid
```

---

### 8.3 Observing with `ps -e | grep`

```bash
ps -e | grep getpid
```

Output (example):

```
12345 ?    00:00:00 getpid
```

- `12345` → PID.
- `getpid` → process name (your program).
- Confirms the process is alive and managed by OS.

---

## 9. Why Process Disappeared After Running

- When you ran `./hello`, it **finished instantly**, so `ps` showed nothing.
- To observe, you need:

  - Infinite loop (`while(1);`) or `sleep()`.
  - Run in background with `&`.
  - Or check very quickly in another terminal.

---

## 10. Key Insights (Brainstorm Answers Polished)

- A program is just bytes on disk; the OS transforms it into a **running process** by:

  1. Loading into memory.
  2. Assigning PID.
  3. Creating PCB.
  4. Scheduling onto CPU.
  5. Running via fetch–decode–execute cycle.

- Without PCB, context switching would fail → processes would restart from scratch.
- OS provides modes (user/kernel) to isolate privileges.
- Tools like `getpid()` and `ps` let us **see theory in practice**.

---
