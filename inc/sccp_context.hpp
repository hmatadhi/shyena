#ifndef _SCCP_CONTEXT_
#define _SCCP_CONTEXT_

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/cstdint.hpp>
#include <m3ua_context.hpp>

class sccp_context {
    boost::uint16_t id;
    boost::uint32_t slr;
    boost::uint32_t dlr;
    m3ua_context m3ua;


    public:   
    	sccp_context();
    	
        sccp_context(boost::uint16_t id,
        	         boost::uint32_t slr,
        	         boost::uint32_t dlr,
        	         m3ua_context m3ua);

        void set_id(boost::uint16_t id) ;
        void set_slr(boost::uint32_t slr) ;
        void set_dlr(boost::uint32_t dlr) ;
        void set_m3ua_context(m3ua_context m3ua);

        boost::uint16_t get_id(void) const;
        boost::uint32_t get_slr(void) const;
        boost::uint32_t get_dlr(void) const;
        m3ua_context get_m3ua_context(void) const;

        bool operator==(const sccp_context &rhs) const;

        std::size_t get_hash(void) const;
        
        void print() const ;

};

typedef boost::shared_ptr<sccp_context> SccpContextPtrType;

#endif
