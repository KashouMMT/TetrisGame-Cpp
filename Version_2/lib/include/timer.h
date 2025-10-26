#ifndef TIMER_H
#define TIMER_H

#include<time.h>

#ifdef __cplusplus
extern "C" {
#endif

time_t timer_init();
int timer_checker(time_t *start_time, int second_interval);

#ifdef __cplusplus
}
#endif

#endif