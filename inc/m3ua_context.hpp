#ifndef _M3UA_CONTEXT_
#define _M3UA_CONTEXT_

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/cstdint.hpp>
#include <sctp_context.hpp>

class m3ua_context {
    boost::uint32_t app_cp;
    sctp_context sctp;

    public:   
    	m3ua_context(void);
    	
        m3ua_context(boost::uint32_t app_cp,
                     sctp_context sctp);

        void set_app_cp(boost::uint32_t app_cp) ;

        void set_sctp_context(sctp_context sctp);

        boost::uint32_t get_app_cp(void) const;

        sctp_context get_sctp_context(void) const;

        std::size_t get_hash(void) const;

        bool operator==(const m3ua_context &rhs) const;
        
        void print() const;

};

typedef boost::shared_ptr<m3ua_context> M3uaContextPtrType;


#endif
