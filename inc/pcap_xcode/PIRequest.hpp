#ifndef _PCAP_PI_REQUEST_
#define _PCAP_PI_REQUEST_

class PIRequest :  public PcapPDU {

    public: 
        PIRequest(const PcapPDU& p);

        virtual  ~PIRequest(void);

};

#endif