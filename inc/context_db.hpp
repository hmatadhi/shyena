#ifndef _CONTEXT_DB_
#define _CONTEXT_DB_

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/cstdint.hpp>
#include <iostream> 
#include <unordered_map> 
#include <pcap_context.hpp>
#include <pcap_procedure.hpp>

using namespace std; 


class pcap_hash
{
public:
    std::size_t operator()(pcap_context const& k) const noexcept
    {
      std::size_t h1;

      h1 = k.get_hash();
      
      return (h1);              
    }
};

class context_db {
    unordered_map<pcap_context, pcap_procedure, pcap_hash> umap;

    public:    
        bool check(pcap_context key);

        pcap_procedure get_value(pcap_context key);

        int add(pcap_context key, pcap_procedure value);

}; 

typedef boost::shared_ptr<context_db> PcapContextDbPtrType;

#endif
