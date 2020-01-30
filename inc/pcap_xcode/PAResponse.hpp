#ifndef _PCAP_PA_RESPONSE_
#define _PCAP_PA_RESPONSE_

class PAResponse :  public PcapPDU {

    public: 
        PAResponse(const PcapPDU& p);

        virtual  ~PAResponse(void);

};

#endif

