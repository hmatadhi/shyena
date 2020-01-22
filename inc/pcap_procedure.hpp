// C++ program to demonstrate functionality of unordered_map 
#ifndef _PCAP_PROCEDURE_
#define _PCAP_PROCEDURE_

#include <iostream> 
#include <boost/cstdint.hpp>
using namespace std; 
  

class pcap_procedure {
    int a;
    int b;
    int c;

    public:    
        pcap_procedure(void);
        
        pcap_procedure(int a, int b, int c);

        void set_param_a(int a); 

        void set_param_b(int b);

        void set_param_c(int c);

        int get_param_a(void) const;

        int get_param_b(void) const;
    
        int get_param_c(void) const;

        void print(); 
};

#endif
