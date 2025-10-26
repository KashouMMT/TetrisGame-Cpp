#include<stdio.h>
#include<time.h>

time_t timer_init() {
    return time(NULL);
}

int timer_checker(time_t *start_time, int second_interval) {
    time_t current_time = time(NULL);
    if(difftime(current_time, *start_time) >= (double) second_interval) {
        printf("%d seconds has passed!\n",second_interval);
        *start_time = current_time;
        return 1;
    }
    return 0;
}