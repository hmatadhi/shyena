#ifndef _PCAP_PDU_
#define _PCAP_PDU_

#include <stdint.h>
#include <string.h>

#include <boost/smart_ptr/shared_ptr.hpp>
#include "pcap_context.hpp"
#include "MessageBuffer.hpp"

class pcap_pdu {
	MessageBufferPtrType mb;


    public: 
    	pcap_pdu(void);

    	virtual  ~pcap_pdu(void);

        void set_tid(boost::uint32_t tid) ;

        void set_sccp_context(sccp_context sccp);

        boost::uint32_t get_tid(void) const;

        sccp_context get_sccp_context(void) const;

        std::size_t get_hash(void) const;

        bool operator==( const pcap_context &rhs) const;

        void print() const;

};


typedef boost::shared_ptr<pcap_pdu> PcapPduPtrType;




#endif