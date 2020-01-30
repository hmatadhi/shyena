#include <iostream> 
#include <unordered_map> 
#include <context_db/PcapContext.hpp>
#include <context_db/PcapProcedure.hpp>
#include <context_db/ContextDb.hpp>
#include <vector>

bool ContextDb::checkKey(PcapContext key)
{
    SccpContext sccpContext = key.getSccpContext();

    if (this->umapSccp.find(sccpContext) == this->umapSccp.end()) {
        return false; 
    }
    else {
        if (this->umapSccp[sccpContext].find(key) == this->umapSccp[sccpContext].end()) {
            return false; 
        }
        else {
            return true; 
        } 
    }
} 

bool ContextDb::checkSession(SccpContext sccpContext)
{
    if (this->umapSccp.find(sccpContext) == this->umapSccp.end()) {
        return false; 
    }
    else {
        return true; 
    }
}

PcapProcedure ContextDb::getValue(PcapContext key)
{
    umapPcap_t umapPcap;
    SccpContext sccpContext = key.getSccpContext();

    umapPcap = this->umapSccp[sccpContext];

    return umapPcap[key];
}

vector<PcapProcedure> ContextDb::getSessionProceduures(SccpContext sccpContext)
{
;
    std::vector<PcapContext> keys;
    keys.reserve(this->umapSccp[sccpContext].size());
    std::vector<PcapProcedure> vals;
    vals.reserve(this->umapSccp[sccpContext].size());

    for(auto kv : this->umapSccp[sccpContext]) {
        keys.push_back(kv.first);
        kv.first.print();
        kv.second.print();
        vals.push_back(kv.second);  
    } 
    return vals;
}

PCAP_RC ContextDb::addProcedure(PcapContext key, PcapProcedure value)
{
    SccpContext sccpContext = key.getSccpContext();
 
    this->umapSccp[sccpContext][key] = value;

    return PCAP_RC_OK;
}