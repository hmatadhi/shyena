#ifndef _SCCP_CONTEXT_
#define _SCCP_CONTEXT_

#include <string>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/cstdint.hpp>
#include <context_db/M3uaContext.hpp>

class SccpContext {
    boost::uint16_t id;
    boost::uint32_t slr;
    boost::uint32_t dlr;
    M3uaContext m3ua;


    public:   
    	SccpContext();
    	
        SccpContext(boost::uint16_t id,
        	         boost::uint32_t slr,
        	         boost::uint32_t dlr,
        	         M3uaContext m3ua);

        void setId(boost::uint16_t id) ;
        void setSLR(boost::uint32_t slr) ;
        void setDLR(boost::uint32_t dlr) ;
        void setM3uaContext(M3uaContext m3ua);

        boost::uint16_t getId(void) const;
        boost::uint32_t getSLR(void) const;
        boost::uint32_t getDLR(void) const;
        M3uaContext getM3uaContext(void) const;

        bool operator==(const SccpContext &rhs) const;

        std::size_t getHash(void) const;
        std::size_t getSessionHash(void) const;

        void print() const ;
        std::string getString() const ;
};

typedef boost::shared_ptr<SccpContext> SccpContextPtrType;

#endif
