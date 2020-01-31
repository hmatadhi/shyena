#include <iostream> 
#include <string>
#include <layer_management/PcapLogger.hpp>
#include <ut/UT_SASMain.hpp>

int UT_SAS::testLogger() 
{ 
    PcapLogger myPcapLogger;

    myPcapLogger.InitializeLogger();

    LogDebug << "Pcap Logger Created";
}


