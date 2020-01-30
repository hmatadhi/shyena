#ifndef _PCAP_PI_RESPONSE_
#define _PCAP_PI_RESPONSE_

class PIResponse :  public PcapPDU {

    public: 
        PIResponse(const PcapPDU& p);

        virtual  ~PIResponse(void);

};

#endif

