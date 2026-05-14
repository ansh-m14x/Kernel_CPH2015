# Custom Kernel for Oppo A31 (MT6765)

This repository contains a highly optimized kernel source for the Oppo A31 (Project: `oppo6765_19581`), based on Linux version 4.9.117. The configuration has been specifically tuned to extract maximum performance from the Helio P35 while maintaining system efficiency.

## ⚡ Advanced Scheduler Tuning (Gaming & Response)

The Completely Fair Scheduler (CFS) logic has been modified in `kernel/sched/features.h` to prioritize task execution speed and touch responsiveness over standard "fairness" protocols.
## ⚖️ Performance & Stability Balance (v2.0)

After real-world testing on the **Oppo A31**, we refined the scheduler features to ensure that extreme performance doesn't interfere with essential hardware functions like physical button response and screen power management.

### ✅ Refined Scheduler Logic
*   **Restored Hardware Sync**: Re-enabled `GENTLE_FAIR_SLEEPERS`. This ensures the Power HAL and System UI can correctly process "sleep" and "wake" signals, fixing the unresponsive button and screen-on issues.
*   **Maintained Snappiness**: We kept `START_DEBIT` disabled and `NEXT_BUDDY` enabled. This keeps app launches fast and touch-to-task transitions smooth without breaking system stability.
*   **Precision Timing**: `HRTICK` remains active at **1ns resolution**, ensuring the kernel still handles gaming frame-times with elite precision.

### 📊 Updated Configuration
| Feature | State | Result |
| :--- | :--- | :--- |
| `GENTLE_FAIR_SLEEPERS` | **TRUE** | Fixes buttons & screen sleep |
| `START_DEBIT` | **FALSE** | Fast app opening |
| `NEXT_BUDDY` | **TRUE** | Lower input latency |
| `HRTICK` | **TRUE** | Nanosecond frame precision |


## 🛠 Build Information
*   **Device**: Oppo A31 (CPH2015 / CPH2073 / CPH2081)
*   **Architecture**: ARM64
*   **Cross-Compiler**: `aarch64-linux-gnu-`
*   **Target Project**: `oppo6765_19581`
*   **Display Resolution**: 720x1600 (HD+)

## ⚠️ Disclaimer
This kernel is intended for technical users and custom ROM developers. Modification of kernel parameters can lead to system instability if not handled correctly. Always ensure you have a backup of your stock `boot.img` before flashing.
