# Custom Kernel for Oppo A31 (MT6765)

This repository contains a highly optimized kernel source for the Oppo A31 (Project: `oppo6765_19581`), based on Linux version 4.9.117. The configuration has been specifically tuned to extract maximum performance from the Helio P35 while maintaining system efficiency.

## ⚡ Advanced Scheduler Tuning (Gaming & Response)

The Completely Fair Scheduler (CFS) logic has been modified in `kernel/sched/features.h` to prioritize task execution speed and touch responsiveness over standard "fairness" protocols.

### 🚀 Performance Optimizations
*   **Low-Latency Wakeups**: Disabled `GENTLE_FAIR_SLEEPERS` to allow waking tasks (like game engines and input drivers) to preempt running tasks more aggressively. This significantly reduces input lag.
*   **Zero-Penalty Task Starts**: Disabled `START_DEBIT`, ensuring new processes and threads are not penalized upon creation, resulting in faster app launches.
*   **Enhanced Cache Locality**: Enabled `NEXT_BUDDY` to prefer scheduling the task that just woke up, ensuring the CPU works on the data most recently touched.
*   **High-Precision Execution**: Enabled `HRTICK` (High-Resolution Timers) to allow for micro-second accurate task switching, reducing micro-stutter during high-refresh scenarios.

### 🛠 Technical Verification
After booting, these features can be verified via the following command (requires root):
`cat /sys/kernel/debug/sched_features`

| Feature | State | Impact |
| :--- | :--- | :--- |
| `GENTLE_FAIR_SLEEPERS` | **DISABLED** | Faster touch response |
| `START_DEBIT` | **DISABLED** | Faster app opening |
| `NEXT_BUDDY` | **ENABLED** | Better CPU data reuse |
| `HRTICK` | **ENABLED** | Smoother frame times (FPS) |

## 🛠 Build Information
*   **Device**: Oppo A31 (CPH2015 / CPH2073 / CPH2081)
*   **Architecture**: ARM64
*   **Cross-Compiler**: `aarch64-linux-gnu-`
*   **Target Project**: `oppo6765_19581`
*   **Display Resolution**: 720x1600 (HD+)

## ⚠️ Disclaimer
This kernel is intended for technical users and custom ROM developers. Modification of kernel parameters can lead to system instability if not handled correctly. Always ensure you have a backup of your stock `boot.img` before flashing.
