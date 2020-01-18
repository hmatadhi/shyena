// C++ program to demonstrate functionality of unordered_map 
#include <iostream> 
using namespace std; 
#include <pcap_context.hpp>  

    
pcap_context::pcap_context(int a, int b)
{
    this->a = a;
    this->b = b;
}

void pcap_context::pcap_context::set_param_a(int a) 
{
    this->a = a;
}

void pcap_context::set_param_b(int b)
{
    this->b = b;
}

int pcap_context::get_param_a(void) const
{
    return this->a;
}

int pcap_context::get_param_b(void) const
{
    return this->b;
}

void pcap_context::print() 
{
    cout << "Context = (" << this->a << "," << this->b << ")" << "\n";
}
