// C++ program to demonstrate functionality of unordered_map 
#ifndef _PCAP_PROCEDURE_
#define _PCAP_PROCEDURE_

#include <iostream> 
#include <boost/cstdint.hpp>
#include "pcap_xcode/PcapPDU.hpp"

class PcapProcedure {
    boost::uint32_t  procedureId;
    boost::uint32_t  procedureStatus;   
    PcapPduPtrType request;
    PcapPduPtrType response;
    PcapPduPtrType failure;
    PcapProcedure *parentProcedure;
    PcapProcedure *childProcedure;    

    public:    
        PcapProcedure(boost::uint32_t);
        
        PcapProcedure(void);

        void print(); 
};

#endif
