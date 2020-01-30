#ifndef _SCTP_CONTEXT_
#define _SCTP_CONTEXT_



#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/cstdint.hpp>

class SctpContext {
    struct sockaddr_in sctp_addr;
    boost::uint16_t stream_id;
    boost::uint16_t assoc_id;

    public: 
    	SctpContext(void);
    	
        SctpContext(boost::uint16_t stream_id,
                     boost::uint16_t assoc_id,
                     struct sockaddr_in sctp_addr);

        void setSctpAddr(struct sockaddr_in sctp_addr) ;

        void setStreamId(boost::uint16_t stream_id);

        void setAssocId(boost::uint16_t assocId);

        struct sockaddr_in getSctpAddr(void) const;

        boost::uint16_t getStreamId(void) const;

        boost::uint16_t getAssocId(void) const;

        std::size_t getHash(void) const;

        bool operator==(const SctpContext &rhs) const;
        
        void print() const;

};

typedef boost::shared_ptr<SctpContext> SctpContextPtrType;


#endif
