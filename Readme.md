# Custom Kernel for Oppo A31 (MT6765)

This repository contains a highly optimized kernel source for the Oppo A31 (Project: `oppo6765_19581`), based on Linux version 4.9.117. The configuration has been specifically tuned to extract maximum performance from the Helio P35 while maintaining system efficiency.

## 🛠️ Kernel Build Specs: Extreme Performance
**Architecture:** ARM64 (aarch64-linux-gnu-)
**Device:** Oppo A31 (MT6765 - oppo6765_19581)

### Performance Locks:
* **Governor:** Forced `Performance` on all 8 cores.
* **Scheduling:** EAS disabled to favor raw throughput over battery efficiency.
* **I/O Boost:** MediaTek I/O Boost enabled for faster asset loading.
* **Memory:** ZRAM with LZ4 compression enabled for aggressive multitasking.

### Optimization Note:
WQ_POWER_EFFICIENT is disabled to ensure background workqueues do not introduce micro-stutter during high CPU load.



## 🛠 Build Information
*   **Device**: Oppo A31 (CPH2015 / CPH2073 / CPH2081)
*   **Architecture**: ARM64
*   **Cross-Compiler**: `aarch64-linux-gnu-`
*   **Target Project**: `oppo6765_19581`
*   **Display Resolution**: 720x1600 (HD+)

## ⚠️ Disclaimer
This kernel is intended for technical users and custom ROM developers. Modification of kernel parameters can lead to system instability if not handled correctly. Always ensure you have a backup of your stock `boot.img` before flashing.
