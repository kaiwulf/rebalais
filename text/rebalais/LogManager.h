/* 
 * LogManager - The log manager for the Rebalais engine.
 *
 * Modification of Dragonfly by Mark Claypool and WPI
 *
 */

#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

// Engine includes.
#include "Rebalais.h"

// Two-letter acronym for easier access to manager.
#define LM rs::LogManager::getInstance()

namespace rs {

const char *LOGFILE_DEFAULT = "rebalais.log";

class LogManager : public Manager {

    public:
        // If logfile is open, close it.
        ~LogManager();

        // Get the one and only instance of the LogManager.
        static LogManager &getInstance();

        // Start up LogManager (open main logfile, usually "rebalais.log").
        // Return 0 if ok, else -1.
        int startUp();

        // Shut down LogManager (close all logfiles).
        void shutDown();

        // Write to logfile.
        // Supports printf() formatting of strings.
        // Return number of bytes written (excluding prepends), -1 if error.
        template<class ... Args>
        int LogManager::writeLog(int log_level, std::string msg, std::string fmt, Args ... args) const

        // Set flush of logfile after each write.
        void setFlush(bool new_do_flush=true);

    private:
        LogManager();                     // Private since a singleton.
        LogManager(LogManager const&);    // Don't allow copy.
        void operator=(LogManager const&);// Don't allow assignment.
        bool m_do_flush;                  // True if flush to disk after write.
        FILE *m_p_f;                      // Pointer to main logfile.
        int log_level;                    // level of log verbosity
};

} // end of namespace df
#endif // __LOG_MANAGER_H__
