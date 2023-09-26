#ifndef _CONFIG_READER_H_
#define _CONFIG_READER_H_

#include <iostream>
#include <map>
namespace Secrets
{
   class ConfigReader
   {
      private:
         std::map<std::string, std::string> m_ConfigSettingMap;
         static ConfigReader* m_pInstance;
      public:
         static ConfigReader* getInstance();
         bool parseFile(std::string fileName = "config.txt");
         bool getValue(std::string tag, int& value);
         bool getValue(std::string tag, std::string& value);
         void dumpFileValues();
      private:
         ConfigReader();
         ~ConfigReader();
         ConfigReader(const ConfigReader& obj){}
         void operator=(const ConfigReader& obj){}
         std::string trim(const std::string& str, const std::string& whitespace = " \t");
         std::string reduce(const std::string& str,
               const std::string& fill = " ",
               const std::string& whitespace = " \t");
   };

}

#endif