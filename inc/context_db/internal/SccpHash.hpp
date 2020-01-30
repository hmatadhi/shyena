#ifndef _SCCP_HASH_
#define _SCCP_HASH_

#include <boost/cstdint.hpp>
#include <unordered_map> 
#include <context_db/SccpContext.hpp>


class SccpHash
{
public:
    std::size_t operator()(SccpContext const& k) const noexcept
    {
      std::size_t h1;

      h1 = k.getSessionHash();
      
      return (h1);              
    }
};

#endif