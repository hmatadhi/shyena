#include <iostream> 
#include <pcap_context.hpp>  
#include <sccp_context.hpp>
#include <string.h>

using namespace std; 

pcap_context::pcap_context(void)
{
    this->tid = 0;
    memset(&this->sccp, 0, sizeof(this->sccp));
}

pcap_context::pcap_context(boost::uint32_t tid, sccp_context sccp)
{
    this->tid = tid;
    this->sccp = sccp;
}

void pcap_context::set_tid(boost::uint32_t tid) 
{
    this->tid = tid;
}

void pcap_context::set_sccp_context(sccp_context sccp)
{
    this->sccp = sccp;
}

boost::uint32_t pcap_context::get_tid(void) const
{
    return this->tid;
}

sccp_context pcap_context::get_sccp_context(void) const
{
    return this->sccp;
}


std::size_t pcap_context::get_hash(void) const
{
	std::size_t h1;
	std::size_t h2;

	h1 = std::hash<int>{}(this->tid);
	h2 = this->sccp.get_hash();

    return (h1 ^ (h2 << 1));
}

bool pcap_context::operator==( const pcap_context &rhs) const
{ 
    return ((this->get_tid() == rhs.get_tid())
        &&  (this->sccp == rhs.sccp));
}

void pcap_context::print() const
{
    cout << "PCAP Transaction Id:" << this->tid << "\n";
    this->sccp.print();
}
