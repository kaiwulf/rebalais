#ifndef __CLOCK_H_
#define __CLOCK_H_

#include "Rebalais.h"

class Clock {
    public:
        Clock();
        long int set_curr_time();
        long int delta();
        long int split() const;
    private:
        long int m_previous_time;
};

#endif