// C++ program to demonstrate functionality of unordered_map 
#ifndef _PCAP_CONTEXT_
#define _PCAP_CONTEXT_

#include <iostream> 
using namespace std; 
  

class pcap_context {
    int a;
    int b;

    public:    
        pcap_context(int a, int b);

        void set_param_a(int a) ;

        void set_param_b(int b);

        int get_param_a(void) const;

        int get_param_b(void) const;

        void print() ;
    
};

#endif 
