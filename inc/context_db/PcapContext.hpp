#ifndef _PCAP_CONTEXT_
#define _PCAP_CONTEXT_

#include <string>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/cstdint.hpp>
#include <context_db/SccpContext.hpp>

class PcapContext {
    boost::uint32_t tid;
    SccpContext sccp;

    public: 
    	PcapContext(void);
    	
        PcapContext(boost::uint32_t tid, SccpContext sccp);

        void setTid(boost::uint32_t tid) ;

        void setSccpContext(SccpContext sccp);

        boost::uint32_t getTid(void) const;

        SccpContext getSccpContext(void) const;

        std::size_t getHash(void) const;

        bool operator==( const PcapContext &rhs) const;

        void print() const;

        std::string getString() const ;        

};


typedef boost::shared_ptr<PcapContext> PcapContextPtrType;



#endif 
