#ifndef _PCAP_PA_REQUEST_
#define _PCAP_PA_REQUEST_


class PARequest :  public PcapPDU {

    public: 
        PARequest(const PcapPDU& p);

        virtual  ~PARequest(void);

};

#endif