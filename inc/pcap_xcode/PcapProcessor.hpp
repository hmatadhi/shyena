#ifndef _PCAP_PROCESSOR_H_
#define _PCAP_PROCESSOR_H_


#include "PCAP-CommonDataTypes.h"
#include "PCAP-PDU-Contents.h"
#include "PCAP-PDU-Descriptions.h"
#include "PCAP-Constants.h"
#include <pcap_xcode/PcapAbort.hpp>

class pcap_processor {
void *pAsnPdu;
const PcapPDU *pPcapPDU;
PcapContextPtrType pCtxt;

public:
	pcap_processor(void *pAsnPdu, PcapContextPtrType pCtct, const PcapPDU *pPcapPDU) ;

    virtual ~pcap_processor();

	PCAP_RC ProcessDecodedPdu(boost::int32_t, boost::uint8_t) const;

	PCAP_RC EncapPcapPdu(boost::int32_t, boost::uint8_t) const;	

private:
	PCAP_RC HandlePositionInitiationRequest(void *pPdu, PcapContextPtrType pCtxt) const;
	PCAP_RC HandlePositionAbort(void *pPdu, PcapContextPtrType pCtxt) const;
	PCAP_RC HandlePositionActivationRequest(void *pPdu, PcapContextPtrType pCtxt) const;
	PCAP_RC HandlePositionInitiationResponse(void *pPdu, PcapContextPtrType pCtxt) const;
	PCAP_RC HandlePositionActivationResponse(void *pPdu, PcapContextPtrType pCtxt) const;
	PCAP_RC HandlePositionInitiationError(void *pPdu, PcapContextPtrType pCtxt) const;
	PCAP_RC HandlePositionActivationError(void *pPdu, PcapContextPtrType pCtxt) const;

	void ExtractPositionAbortData(PcapAbort & pcapAbortArg,pcap::ASN1T_Abort& PcapAbortRequesteArg) const;		
};

#endif