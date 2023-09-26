#include <iostream>
#include <cstdlib>
#include <ctime>

#include "logger.h"
#include "ConfigReader.h"

using namespace std;
using namespace Logging;
using namespace Secrets;

Logger* Logger::m_Instance = 0;

const string logFileName = "MyLogFile.log";

Logger::Logger()
{
   m_File.open(logFileName.c_str(), ios::out|ios::app);
   configure();
   logFilesCount  = 1;

   InitializeCriticalSection(&m_Mutex);
}

Logger::~Logger()
{
   m_File.close();
   DeleteCriticalSection(&m_Mutex);
}

Logger* Logger::getInstance() throw ()
{
   if (m_Instance == 0) 
   {
      m_Instance = new Logger();
   }
   return m_Instance;
}

void Logger::lock()
{
   EnterCriticalSection(&m_Mutex);
}

void Logger::unlock()
{
   LeaveCriticalSection(&m_Mutex);
}

void Logger::logIntoFile(std::string& data)
{
   unsigned long pos = m_File.tellp();
   if(pos + data.size() > logSize)
   {
		rollLogFiles();	
   }
   
   lock();
   m_File << getCurrentTime() << "  " << data << endl;
   unlock();
}

void Logger::logOnConsole(std::string& data)
{
   cout << getCurrentTime() << "  " << data << endl;
}

string Logger::getCurrentTime()
{
   string currTime;
   time_t now = time(0); 
   currTime.assign(ctime(&now));

   string currentTime = currTime.substr(0, currTime.size()-1);
   return currentTime;
}

void Logger::error(const char* text) throw()
{		
   string data;
   data.append("[ERROR]: ");
   data.append(text);

   if(m_LogType == FILE_LOG && m_LogLevel)
   {
      logIntoFile(data);
   }
   else if(m_LogType == CONSOLE && m_LogLevel)
   {
      logOnConsole(data);
   }
}

void Logger::error(std::string& text) throw()
{
   error(text.data());
}

void Logger::error(std::ostringstream& stream) throw()
{
   string text = stream.str();
   error(text.data());
}

void Logger::alarm(const char* text) throw()
{
   string data;
   data.append("[ALARM]: ");
   data.append(text);

   if(m_LogType == FILE_LOG && m_LogLevel)
   {
      logIntoFile(data);
   }
   else if(m_LogType == CONSOLE && m_LogLevel)
   {
      logOnConsole(data);
   }
}

void Logger::alarm(std::string& text) throw()
{
   alarm(text.data());
}

void Logger::alarm(std::ostringstream& stream) throw()
{
   string text = stream.str();
   alarm(text.data());
}

void Logger::always(const char* text) throw()
{
   string data;
   data.append("[ALWAYS]: ");
   data.append(text);

   if(m_LogType == FILE_LOG && m_LogLevel)
   {
      logIntoFile(data);
   }
   else if(m_LogType == CONSOLE && m_LogLevel)
   {
      logOnConsole(data);
   }
}

void Logger::always(std::string& text) throw()
{
   always(text.data());
}

void Logger::always(std::ostringstream& stream) throw()
{
   string text = stream.str();
   always(text.data());
}
 
void Logger::buffer(const char* text) throw()
{
   if((m_LogType == FILE_LOG) && (m_LogLevel <= LOG_LEVEL_BUFFER))
   {
      lock();
      m_File << text << endl;
      unlock();
   }
   else if((m_LogType == CONSOLE) && (m_LogLevel <= LOG_LEVEL_BUFFER))
   {
      cout << text << endl;
   }
}

void Logger::buffer(std::string& text) throw()
{
   buffer(text.data());
}

void Logger::buffer(std::ostringstream& stream) throw()
{
   string text = stream.str();
   buffer(text.data());
}

void Logger::info(const char* text) throw()
{
   string data;
   data.append("[INFO]: ");
   data.append(text);

   if((m_LogType == FILE_LOG) && (m_LogLevel <= LOG_LEVEL_INFO))
   {
      logIntoFile(data);
   }
   else if((m_LogType == CONSOLE) && (m_LogLevel <= LOG_LEVEL_INFO))
   {
      logOnConsole(data);
   }
}

void Logger::info(std::string& text) throw()
{
   info(text.data());
}

void Logger::info(std::ostringstream& stream) throw()
{
   string text = stream.str();
   info(text.data());
}

void Logger::trace(const char* text) throw()
{
   string data;
   data.append("[TRACE]: ");
   data.append(text);

   if((m_LogType == FILE_LOG) && (m_LogLevel <= LOG_LEVEL_TRACE))
   {
      logIntoFile(data);
   }
   else if((m_LogType == CONSOLE) && (m_LogLevel <= LOG_LEVEL_TRACE))
   {
      logOnConsole(data);
   }
}

void Logger::trace(std::string& text) throw()
{
   trace(text.data());
}

void Logger::trace(std::ostringstream& stream) throw()
{
   string text = stream.str();
   trace(text.data());
}

void Logger::debug(const char* text) throw()
{
   string data;
   data.append("[DEBUG]: ");
   data.append(text);

   if((m_LogType == FILE_LOG) && (m_LogLevel <= LOG_LEVEL_DEBUG))
   {
      logIntoFile(data);
   }
   else if((m_LogType == CONSOLE) && (m_LogLevel <= LOG_LEVEL_DEBUG))
   {
      logOnConsole(data);
   }
}

void Logger::debug(std::string& text) throw()
{
   debug(text.data());
}

void Logger::debug(std::ostringstream& stream) throw()
{
   string text = stream.str();
   debug(text.data());
}

void Logger::updateLogLevel(LogLevel logLevel)
{
   m_LogLevel = logLevel;
}

void Logger::enaleLog()
{
   m_LogLevel = ENABLE_LOG; 
}

void Logger:: disableLog()
{
   m_LogLevel = DISABLE_LOG;
}

void Logger::updateLogType(LogType logType)
{
   m_LogType = logType;
}

void Logger::enableConsoleLogging()
{
   m_LogType = CONSOLE; 
}

void Logger::enableFileLogging()
{
   m_LogType = FILE_LOG ;
}

void Logger::updateMaxLogFiles(const ssize_t maxFiles)
{
    if(maxFiles > 0)
	maxLogFiles = maxFiles;

    else
	maxLogFiles = MAX_LOG_FILES;

}

void Logger::updateLogSize(const ssize_t size)
{
    if(size > 0)
	logSize = size;

    else
        logSize = LOG_FILE_SIZE;
}

void Logger::rollLogFiles()
{
    m_File.close();	

    if(maxLogFiles > 1)
    {
         string logFile = logFileName.substr(0, logFileName.length()-4); 

         if(logFilesCount >= maxLogFiles)
         {
             string deleteFileName = logFile + "_" + to_string(maxLogFiles-1) + ".tar.gz";
             remove(deleteFileName.c_str());
    
             logFilesCount--; 	
         }

        for(int i = logFilesCount; i >= 2; --i)
       {
             string oldLogFileName = logFile + "_" + to_string(i-1) + ".tar.gz";
             string newLogFileName = logFile + "_" + to_string(i) + ".tar.gz";

             rename(oldLogFileName.c_str(), newLogFileName.c_str());
         }

         string cmd = "tar -cf " + logFile + "_1.tar.gz " + logFileName;

        system(cmd.c_str());
    }

    remove(logFileName.c_str());

    m_File.open(logFileName.c_str(), ios::out|ios::app);

    if(logFilesCount < maxLogFiles)
    {
        logFilesCount++;
    }
}
 
void Logger::configure()
{
    ConfigReader* config = ConfigReader::getInstance();

    config->parseFile();
 
    LogLevel logLevel;
    LogType logType;

    string logLevel_str;
    string logType_str;

    int logFiles;
    int logFileSize;

    if( config->getValue("log_level", logLevel_str) )
    {
        if(logLevel_str == "ENABLE_LOG" || logLevel_str == "1")
            logLevel = ENABLE_LOG;

        else if(logLevel_str == "LOG_LEVEL_INFO" || logLevel_str == "2")
            logLevel = LOG_LEVEL_INFO;

        else if(logLevel_str == "LOG_LEVEL_BUFFER" || logLevel_str == "3")
            logLevel = LOG_LEVEL_BUFFER;

        else if(logLevel_str == "LOG_LEVEL_TRACE" || logLevel_str == "4")
            logLevel = LOG_LEVEL_TRACE;

        else if(logLevel_str == "LOG_LEVEL_DEBUG" || logLevel_str == "5")
            logLevel = LOG_LEVEL_DEBUG;

        else if(logLevel_str == "DISABLE_LOG" || logLevel_str == "6")
            logLevel = DISABLE_LOG;

        else
            logLevel = LOG_LEVEL_TRACE;
    }

    else
        logLevel = LOG_LEVEL_TRACE;


    if( config->getValue("log_type", logType_str) )
    {
        if(logType_str == "NO_LOG" || logType_str == "1")
            logType = NO_LOG;
 
        else if(logType_str == "CONSOLE" || logType_str == "2")
            logType = CONSOLE;

        else
            logType = FILE_LOG;
    }

    else
        logType = FILE_LOG;



    if( !config->getValue("max_log_files", logFiles) )
        logFiles = MAX_LOG_FILES;

    if( !config->getValue("log_size", logFileSize) )
        logFileSize = LOG_FILE_SIZE;


    m_LogLevel = logLevel;
    m_LogType = logType;
    
    updateMaxLogFiles(logFiles);

    updateLogSize(logFileSize);

}