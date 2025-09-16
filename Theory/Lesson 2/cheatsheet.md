

# 📝 OS Revision Sheet — Day-1 (Intro + Architecture)

---

## 1. Why OS Exists

* Without OS: chaos → no CPU fairness, memory corruption, I/O collisions, no protection.
* OS = **referee, illusionist, glue**:

  * **Referee** → ensures fairness & safety (CPU scheduling, access control).
  * **Illusionist** → creates abstractions (virtual memory, file system).
  * **Glue** → APIs & convenience (system calls, libraries).

---

## 2. OS as Resource Manager

* **CPU** → scheduling (decide which process runs).
* **Memory** → allocation, isolation, virtual memory.
* **Devices (I/O)** → drivers, multiplexing.
* **Storage** → file system abstractions.
* **Networking** → sockets, protocol handling.

**Analogy**: Airport control tower (OS) directs planes (programs) on runways (resources).

---

## 3. Kernel vs User Mode

* **Kernel mode**: unrestricted access (OS code, drivers, low-level mgmt).
* **User mode**: restricted (apps), must use system calls to request services.
* Protection boundary prevents crashes & malicious access.

---

## 4. OS Architectures

* **Monolithic** → all services in one big kernel (fast, but less modular).
* **Microkernel** → minimal kernel + user-space services (more modular, but slower IPC).
* **Modular (Linux)** → monolithic base + loadable modules (drivers, filesystems).

**Reality check on Ubuntu (EC2):**

* `uname -r` → kernel version.
* `lsmod` → loaded kernel modules.
* `dmesg` → boot log & driver load messages.
* `/proc` → virtual FS exposing kernel structures.

---

## 5. Processes (Preview for Day-2)

* Program = passive file (bytes on disk).
* Process = running instance (active, with state + resources).
* Each process has a **PID** and a **PCB** to track state.

---

## 6. Key Terms

* **PCB (Process Control Block):** stores registers, state, memory pointers, open files, scheduling info.
* **Context Switching:** saving one PCB, restoring another → enables multitasking.
* **/proc FS:** kernel → user interface for system and process info.

---

## 7. Brainstorm Answers (Your Work Polished)

* **Without OS**: CPU hogging, memory corruption, device collisions, no security.
* **PCB needed**: Without it, after a context switch the CPU wouldn’t know where to resume → process restarts from scratch.
* **getpid() code**: shows how process can retrieve its PID (via system call).
* **ps -e**: lists all processes; under the hood, kernel walks through PCBs.

---

✅ Quick Recap:
OS = **Referee (safety), Illusionist (abstraction), Glue (convenience)**.
Kernel ≠ user mode. Linux = modular monolithic kernel. PCB is the “process identity card.”

---


