#include "Rebalais.h"

char *getSystemTime() {
    static char time_str[30];

    time_t now;
    time(&now);
    struct tm *p_time = localtime(&now);

    sprintf(time_str, "%02d:%02d:%02d",
        p_time->tm_hour,
        p_time->tm_min,
        p_time->time_sec
    );

    return time_str;
}

