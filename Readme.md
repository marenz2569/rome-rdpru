# rome rdpru

According to [AMD64 Architecture Programmer's Manual Volume 3: General-Purpose and System Instructions](https://www.amd.com/system/files/TechDocs/24594.pdf) the RDPRU instruction allows to read the APERF and MPERF value.
For Rome procesors the effective frequency is `P0 * APERF / MPERF`. [Preliminary Processor Programming Reference (PPR) for AMD Family 17h Model 31h, Revision B0 Processors, Sec. 2.1.5](https://developer.amd.com/wp-content/resources/55803_B0_PUB_0_91.pdf)

This programm outputs the difference of APERF and MPERF and their quotient every second.
