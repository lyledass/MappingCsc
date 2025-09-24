#ifndef GMMKTIME_H
#define GMMMKTIME_H

#define TIME_T_MAX_BITS 32

#include <time.h>

time_t gmmktime(struct tm *tm);

#endif
