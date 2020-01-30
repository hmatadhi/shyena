#ifndef PCAP_ABORT_REQUEST_BUILDER_HPP
#define PCAP_ABORT_REQUEST_BUILDER_HPP

#if 0
#include "PCAP-PDU-Contents.h"
#include "PCAP-PDU-Descriptions.h"
#include "PCAP-PDU-Contents.h"
#include <pcap_xcode/MessageHelpers/PcapMessageBuilder.hpp>
#include <context_db/pcap_context.hpp>

class PcapAbortRequestBuilderType : public PcapMessageBuilderType 
{
public:
    explicit PcapAbortRequestBuilderType
    (
        //boost::shared_ptr<pcap_context> pCtxtArg,
        const bool  DebugArg
    );

    ~PcapAbortRequestBuilderType();

private:
    virtual bool BuildPdu();
    pcap::ASN1T_Abort* BuildLocAbortReq();
};
#endif

#endif /* LOCATION_ABORT_REQUEST_BUILDER_HPP */ 