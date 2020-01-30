#ifndef _M3UA_CONTEXT_
#define _M3UA_CONTEXT_

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/cstdint.hpp>
#include <context_db/SctpContext.hpp>

class M3uaContext {
    boost::uint32_t app_cp;
    SctpContext sctp;

    public:   
    	M3uaContext(void);
    	
        M3uaContext(boost::uint32_t app_cp,
                     SctpContext sctp);

        void setAppCP(boost::uint32_t app_cp) ;

        void setSctpContext(SctpContext sctp);

        boost::uint32_t getAppCP(void) const;

        SctpContext getSctpContext(void) const;

        std::size_t getHash(void) const;

        bool operator==(const M3uaContext &rhs) const;
        
        void print() const;

};

typedef boost::shared_ptr<M3uaContext> M3uaContextPtrType;


#endif
