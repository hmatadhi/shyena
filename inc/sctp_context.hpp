#ifndef _SCTP_CONTEXT_
#define _SCTP_CONTEXT_



#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/cstdint.hpp>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>




class sctp_context {
    struct sockaddr_in sctp_addr;
    boost::uint16_t stream_id;
    boost::uint16_t assoc_id;

    public: 
    	sctp_context(void);
    	
        sctp_context(boost::uint16_t stream_id,
                     boost::uint16_t assoc_id,
                     struct sockaddr_in sctp_addr);

        void set_sctp_addr(struct sockaddr_in sctp_addr) ;

        void set_stream_id(boost::uint16_t stream_id);

        void set_assoc_id(boost::uint16_t assocId);

        struct sockaddr_in get_sctp_addr(void) const;

        boost::uint16_t get_stream_id(void) const;

        boost::uint16_t get_assoc_id(void) const;

        std::size_t get_hash(void) const;

        bool operator==(const sctp_context &rhs) const;
        
        void print() const;

};

typedef boost::shared_ptr<sctp_context> SctpContextPtrType;


#endif
