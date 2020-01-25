#include <iostream>
#include <context_db/pcap_procedure.hpp>

using namespace std; 


pcap_procedure::pcap_procedure(void)
{
    this->a = 0;
    this->b = 0;
    this->c = 0;
}

  


pcap_procedure::pcap_procedure(int a, int b, int c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

void pcap_procedure::set_param_a(int a) 
{
    this->a = a;
}

void pcap_procedure::set_param_b(int b)
{
    this->b = b;
}

void pcap_procedure::set_param_c(int c)
{
    this->c = c;
}

int pcap_procedure::get_param_a(void) const
{
    return this->a;
}

int pcap_procedure::get_param_b(void) const
{
    return this->b;
}

int pcap_procedure::get_param_c(void) const
{
    return this->c;
}

void pcap_procedure::print() 
{
    cout << "Value = (" << this->a << "," 
                        << this->b << ","
                        << this->c << ")" << "\n";
}
