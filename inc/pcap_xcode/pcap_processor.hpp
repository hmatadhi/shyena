#ifndef _PCAP_PROCESSOR_H_
#define _PCAP_PROCESSOR_H_

class pcap_processor {
void *pPdu;
PcapContextPtrType pCtxt;

public:
	pcap_processor(void *pPdu, PcapContextPtrType pCtct) ;

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
};

#endif