​King Kernel for Oppo A31 (MT6765)
​King Kernel is a high-performance, precision-tuned kernel source for the Oppo A31 (CPH2015/Project: oppo6765_19581). This project focuses on eliminating proprietary overhead, streamlining the block I/O path, and providing a modern, responsive foundation for custom ROM development.
​🛠 Core Project Upgrades
​1. Core Upstream Base Bump
​Version Update: Upstreamed from Linux 4.9.117 to 4.9.119.
​Impact: Integrates essential security patches, upstream bug fixes, and critical stability improvements.
​2. Native F2FS Integration
​Filesystem Engine: Implemented full, high-performance F2FS (Flash-Friendly File System) drivers.
​Optimization: Accelerates R/W capabilities, optimizes gaming block execution, and reduces application initialization latency.
​3. SCSI & Buffer Management Refactor
​Refactored Logic: Removed complex scsi_log_buf structure and per-CPU bitmask management.
​Implementation: Uses direct kmalloc (128-byte, GFP_ATOMIC) for allocation, preventing potential deadlocks.
​4. Block Layer & I/O Scheduling (CFQ Tuning)
​Optimized the CFQ scheduler for eMMC hardware:
​cfq_quantum: Increased from 8 to 16.
​cfq_back_seek_penalty: Reduced from 2 to 1 for faster random-access patterns.
​Accounting Override: Bypassed filesystem-level request accounting to save CPU cycles.
​5. Optimized Integer Square Root
​Fast-Forward Logic: Added bit-skipping loop to reduce iteration counts for smaller inputs while maintaining floor(sqrt(x)) accuracy.
​6. Advanced CPU & Power Management
​Optimization Flags: Compiled with -mcpu=cortex-a53 and -mtune=cortex-a53 for hardware-specific efficiency.
​Systracker Removal: Stripped MTK_SYSTRACKER and MTK_MLOG to eliminate background telemetry and thermal overhead.
​RT Scheduler Boost: Removed Real-Time (RT) throttling to provide unrestricted performance for UI and gaming workloads.
​7. Battery Reliability
​Battery Profile: Added missing column properties for Fuel Gauge (FG) profiling to ensure accurate capacity reporting.
