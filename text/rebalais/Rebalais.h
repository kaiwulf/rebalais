#ifndef __Rebalais_H_
#define __Rebalais_H_

/* linux system includes */
#include <sys/time.h>

/* C includes */
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

/* C++ includes */
#include <map>
#include <time>

/* Will need for more advanced 2D & 3D section of engine */
#include <filesystem>
#include <fstream>

/* Engine headers */
#include "Manager.h"
#include "LogManager.h"

// Constants and macros
#define TARGET_TIME 20000000 /* to sleep for 20 milliseconds */
#define ONE_MIL 1000000
#define ONE_K 1000

// Function decl


// Functions

/* sleep for 20 milliseconds */
inline int game_sleep() {
    int sleeperr;
    struct timespec sleep_time;
    sleep_time.tv_sec = 0;
    sleep_time.tv_nsec = TARGET_TIME;
    return nanosleep(&sleep_time, NULL);

}

#endif