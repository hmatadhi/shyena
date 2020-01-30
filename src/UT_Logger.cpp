#include <iostream> 
#include <string>
#include <layer_management/Logger.hpp>
#include <UT/UT_SASMain.hpp>

#define PCAP_LOGTAG  "SAS_PCAP"
class PcapLogger {
private:
       int logDebugLevel;
       std::string LogDir;
public:  
       PcapLogger() {
           this->logDebugLevel = 0;
           this->LogDir = ".";
       }  

       /* Function to Initialize Logger */
       void InitializeLogger()
       {
           boost::log::trivial::severity_level DebugLevel = boost::log::trivial::debug;
       
           switch(this->logDebugLevel)
           {
               case 0:
                   DebugLevel = boost::log::trivial::trace;
                   break;
               case 1:
                   DebugLevel = boost::log::trivial::debug;
                   break;
               case 2:
                   DebugLevel = boost::log::trivial::info;
                   break;
               case 3:
                   DebugLevel = boost::log::trivial::warning;
                   break;
               case 4:
                   DebugLevel = boost::log::trivial::error;
                   break;
               case 5:
                   DebugLevel = boost::log::trivial::fatal;
                   break;
           }
       
           InitLogger(PCAP_LOGTAG, DebugLevel,this->LogDir);
       }
};

int UT_SAS::testLogger() 
{ 
    PcapLogger myPcapLogger;

    LogDebug << "Pcap Logger Created";
}


