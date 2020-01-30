#ifndef _PCAP_HASH_
#define _PCAP_HASH_

#include <boost/cstdint.hpp>
#include <unordered_map> 
#include <context_db/PcapContext.hpp>

class PcapHash
{
public:
    std::size_t operator()(PcapContext const& k) const noexcept
    {
      std::size_t h1;

      h1 = k.getHash();
      
      return (h1);              
    }
};

#endif