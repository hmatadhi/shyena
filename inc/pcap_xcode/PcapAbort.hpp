#ifndef _PCAP_ABORT_
#define _PCAP_ABORT_

class PcapAbort :  public PcapPDU {

    public: 
        PcapAbort(const PcapPDU& p);

        virtual  ~PcapAbort(void);

        /* PCAP Cause -- Only INcase of Error */
        pcap::ASN1T_Cause   aPcapCause;
};

#endif