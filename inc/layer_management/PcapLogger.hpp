#ifndef _PCAP_LOGGER_
#define _PCAP_LOGGER_
#include <iostream> 
#include <string>
#include <layer_management/internal/Logger.hpp>

#define PCAP_LOGTAG  "SAS_PCAP"
class PcapLogger {
private:
       int logDebugLevel;
       std::string LogDir;
public:  
       PcapLogger(); 

       /* Function to Initialize Logger */
       void InitializeLogger();
};
#endif