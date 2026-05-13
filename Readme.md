# Custom Kernel for Oppo A31 (MT6765)

This repository contains a highly optimized kernel source for the Oppo A31 (Project: `oppo6765_19581`), based on Linux version 4.9.117. The configuration has been specifically tuned to extract maximum performance from the Helio P35 while maintaining system efficiency.

## 🚀 Key Optimizations & Advantages

### 1. Advanced Scheduler & CPU Performance
*   **WALT Scheduler (`CONFIG_SCHED_WALT=y`)**: Replaces the standard PELT load tracking with Window-Assisted Load Tracking. This allows the kernel to respond more aggressively to sudden bursts in CPU demand, reducing frame drops in heavy games like PUBG or Free Fire.
*   **Energy Aware Scheduling (`CONFIG_DEFAULT_USE_ENERGY_AWARE=y`)**: Optimizes task placement across the Helio P35's octa-core architecture to ensure performance is delivered without unnecessary battery drain.
*   **I/O Boost (`CONFIG_MTK_IO_BOOST=y`)**: Speeds up app launch times by temporarily increasing system frequencies during heavy storage read/write operations.

### 2. Networking (Gaming & Ping)
*   **Google BBR (`CONFIG_TCP_CONG_BBR=y`)**: Implements the Bottleneck Bandwidth and RTT congestion control. This is critical for mobile gaming, as it significantly reduces latency (ping) and prevents packet loss on unstable Wi-Fi or LTE connections.
*   **Advanced Routing**: Enabled `CONFIG_IP_MROUTE_MULTIPLE_TABLES` to ensure better compatibility with modern Android VPNs, custom DNS settings, and tethering.

### 3. Memory Management (ZRAM)
*   **ZRAM Support (`CONFIG_ZRAM=y`)**: Optimized for the Oppo A31's RAM configurations by compressing idle memory pages into a virtual swap area, allowing for better multi-tasking.
*   **Fast Booting (`CONFIG_RD_LZ4=y`)**: The ramdisk is compressed using LZ4, the fastest decompression algorithm available, significantly reducing cold boot times.
*   **Crypto Support**: Includes `CONFIG_CRYPTO_ZSTD=y`, providing the option for ZSTD compression—a superior balance between high RAM compression ratios and low CPU overhead.

### 4. System Stability & Lean Build
*   **Reduced Debug Overhead**: Disabled `CONFIG_DEBUG_INFO` and `CONFIG_CGROUP_DEBUG` to strip unnecessary symbols. This results in a smaller kernel image (`Image.gz-dtb`), faster build times, and lower CPU jitter.
*   **Hardened Security**: Kept `CONFIG_CC_STACKPROTECTOR_STRONG=y` to ensure the kernel remains resistant to buffer overflow attacks without sacrificing performance.
*   **Preemptive Kernel (`CONFIG_PREEMPT=y`)**: Lowers system latency by allowing higher-priority tasks to interrupt lower-priority kernel code immediately, resulting in a "snappier" UI feel.

## 🛠 Build Information
*   **Device**: Oppo A31 (CPH2015 / CPH2073 / CPH2081)
*   **Architecture**: ARM64
*   **Cross-Compiler**: `aarch64-linux-gnu-`
*   **Target Project**: `oppo6765_19581`
*   **Display Resolution**: 720x1600 (HD+)

## ⚠️ Disclaimer
This kernel is intended for technical users and custom ROM developers. Modification of kernel parameters can lead to system instability if not handled correctly. Always ensure you have a backup of your stock `boot.img` before flashing.
