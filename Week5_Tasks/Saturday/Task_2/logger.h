#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <process.h>

namespace Logging
{

    #define LOG_ERROR(x)    Logger::getInstance()->error(x)
    #define LOG_ALARM(x)    Logger::getInstance()->alarm(x)
    #define LOG_ALWAYS(x)   Logger::getInstance()->always(x)
    #define LOG_INFO(x)     Logger::getInstance()->info(x)
    #define LOG_BUFFER(x)   Logger::getInstance()->buffer(x)
    #define LOG_TRACE(x)    Logger::getInstance()->trace(x)
    #define LOG_DEBUG(x)    Logger::getInstance()->debug(x)

    #define MAX_LOG_FILES 10
    #define LOG_FILE_SIZE 3000

    typedef enum LOG_LEVEL
    {
       ENABLE_LOG	    = 1,
       LOG_LEVEL_INFO	= 2,
       LOG_LEVEL_BUFFER	= 3,
      LOG_LEVEL_TRACE   = 4,
      LOG_LEVEL_DEBUG   = 5,
      DISABLE_LOG	    = 6
    } LogLevel;
    typedef enum LOG_TYPE
    {
      NO_LOG            = 1,
      CONSOLE           = 2,
      FILE_LOG          = 3,
    }LogType;

    class Logger
    {
        public:
         static Logger* getInstance() throw ();

         void error(const char* text) throw();
         void error(std::string& text) throw();
         void error(std::ostringstream& stream) throw();

         void alarm(const char* text) throw();
         void alarm(std::string& text) throw();
         void alarm(std::ostringstream& stream) throw();

         void always(const char* text) throw();
         void always(std::string& text) throw();
         void always(std::ostringstream& stream) throw();

         void buffer(const char* text) throw();
         void buffer(std::string& text) throw();
         void buffer(std::ostringstream& stream) throw();

         void info(const char* text) throw();
         void info(std::string& text) throw();
         void info(std::ostringstream& stream) throw();

         void trace(const char* text) throw();
         void trace(std::string& text) throw();
         void trace(std::ostringstream& stream) throw();

         void debug(const char* text) throw();
         void debug(std::string& text) throw();
         void debug(std::ostringstream& stream) throw();

         void updateLogLevel(LogLevel logLevel);
         void enaleLog();  
         void disableLog(); 

         void updateLogType(LogType logType);
         void enableConsoleLogging();
         void enableFileLogging();

         void updateMaxLogFiles(const ssize_t maxFiles);
         void updateLogSize(const ssize_t size);
         

      protected:
         Logger();
         ~Logger();

         void lock();
         void unlock();

         std::string getCurrentTime();

      private:
         void logIntoFile(std::string& data);
         void logOnConsole(std::string& data);
         Logger(const Logger& obj) {}
         void operator=(const Logger& obj) {}
         void rollLogFiles();
         void configure();

      private:
         static Logger*          m_Instance;
         std::ofstream           m_File;

         CRITICAL_SECTION        m_Mutex;

         LogLevel                m_LogLevel;
         LogType                 m_LogType;
          
         unsigned int		 logSize; 
         unsigned int		 maxLogFiles; 
         unsigned int		 logFilesCount;
    };
}
#endif 