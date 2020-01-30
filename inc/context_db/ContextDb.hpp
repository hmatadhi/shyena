#ifndef _CONTEXT_DB_
#define _CONTEXT_DB_

#include <iostream> 
#include <vector>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/cstdint.hpp>
#include <unordered_map> 
#include <Pcap.hpp>
#include <context_db/PcapContext.hpp>
#include <context_db/PcapProcedure.hpp>
#include <context_db/internal/PcapHash.hpp>
#include <context_db/internal/SccpHash.hpp>

using namespace std;

typedef unordered_map<PcapContext, PcapProcedure, PcapHash> umapPcap_t;
typedef unordered_map<SccpContext, umapPcap_t, SccpHash> umapSccp_t;

class ContextDb {
      umapSccp_t umapSccp;

    public:    
        bool checkKey(PcapContext key);

        bool checkSession(SccpContext sccpContext);

        PcapProcedure getValue(PcapContext key);

        vector<PcapProcedure> getSessionProceduures(SccpContext sccpContext);

        PCAP_RC addProcedure(PcapContext key, PcapProcedure value);

}; 

typedef boost::shared_ptr<ContextDb> PcapContextDbPtrType;

#endif
