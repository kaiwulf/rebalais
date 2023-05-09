#include "Rebalais.h"

long int Clock::set_curr_time() {
    struct timeval current_tv;
    gettimeofday(&current_tv, NULL);
    m_prevoius_time = current_tv.tv_sec*ONE_K + current_tv.tv_nsec/ONE_MIL;
}

Clock::Clock() {
    Clock::set_curr_time();
}

long int Clock::delta() {
    struct timespec before_ts, after_ts;
    clock_gettime(CLOCK_REALTIME, &before_ts);
    // do stuff
    clock_gettime(CLOCK_REALTIME, &after_ts);

    long int before_msec = before_ts.tv_sec*ONE_K + before_ts.tv_nsec/ONE_MIL;
    long int after_msec = after_msec.tv_sec*ONE_K + after_ts.tv_nsec/ONE_MIL;
    long int elapsed_time = after_msec - before_msec;
    Clock::set_curr_time();
    return elapsed_time;
}

long int Clock::split() {

}