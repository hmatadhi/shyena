// C++ program to demonstrate functionality of unordered_map 
#ifndef _CONTEXT_DB_
#define _CONTEXT_DB_

#include <iostream> 
#include <unordered_map> 
#include <pcap_context.hpp>
#include <pcap_procedure.hpp>

using namespace std; 


struct pcap_hash
{
    std::size_t operator()(pcap_context const& k) const noexcept
    {
      using std::size_t;
      using std::hash;


      int a, b;
      a = k.get_param_a();
      b = k.get_param_b();

      std::size_t h1  = std::hash<int>{}(a);
      std::size_t h2  = std::hash<int>{}(b);

      return (h1 ^ (h2 << 1));
               
    }
};

namespace std
{

    template<> struct hash<pcap_context>
    {
       std::size_t operator()(pcap_context const& k) const noexcept
       {
         using std::size_t;
         using std::hash;


         int a, b;
         a = k.get_param_a();
         b = k.get_param_b();

         std::size_t h1  = std::hash<int>{}(a);
         std::size_t h2  = std::hash<int>{}(b);

         return (h1 ^ (h2 << 1));
                  
       }
    };
}


class context_db {
    unordered_map<pcap_context, pcap_procedure> umap;

    public:    
        bool check(pcap_context key);

        pcap_procedure get_value(pcap_context key);

        int add(pcap_context key, pcap_procedure value);

}; 

#endif
