# rome rdpru

According to [AMD64 Architecture Programmer's Manual Volume 3: General-Purpose and System Instructions]() the RDPRU instruction allows to read the APERF and MPERF value.
For Rome procesors the effective frequency is P0 * APERF / MPERF. [citation]

This programm outputs the difference of APERF and MPERF and quotient of these two every second.
