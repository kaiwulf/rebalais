#include "Rebalais.h"

LogManager::~LogManager() {
    m_do_flush = false;
    m_p_f = NULL;
}

int LogManager::startUp() {
    m_p_f = fopen(LOGFILE_DEFAULT);
    if(m_p_f != NULL) {
        LogManager::writeLog(/* write log input? */);
    }
}

void LogManager::Shutdown() {
    fclose(m_p_f);
}

template<class ... Args>
int LogManager::writeLog(int log_level, std::string msg, std::string fmt, Args ... args) const {
    // TO-DO: Adjust to send errors to log file
    // TO-DO: make gradiations for more granular verbosity
    fprintf(stderr, msg.c_str());
    if(log_level >= this.log_level) vfprintf(stderr, fmt.c_str(), args ... );
}

void LogManager::setFlush(bool new_do_flush=true) {
    if(new_do_flush) m_do_flush = true;
}