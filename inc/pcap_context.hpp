#ifndef _PCAP_CONTEXT_
#define _PCAP_CONTEXT_

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/cstdint.hpp>
#include <sccp_context.hpp>

class pcap_context {
    boost::uint32_t tid;
    sccp_context sccp;

    public: 
    	pcap_context(void);
    	
        pcap_context(boost::uint32_t tid, sccp_context sccp);

        void set_tid(boost::uint32_t tid) ;

        void set_sccp_context(sccp_context sccp);

        boost::uint32_t get_tid(void) const;

        sccp_context get_sccp_context(void) const;

        std::size_t get_hash(void) const;

        bool operator==( const pcap_context &rhs) const;

        void print() const;

};


typedef boost::shared_ptr<pcap_context> PcapContextPtrType;



#endif 
