#include <iostream>   
#include <context_db/sccp_context.hpp>
#include <context_db/m3ua_context.hpp>
#include <string.h>    

using namespace std;

sccp_context::sccp_context(boost::uint16_t tid,
					       boost::uint32_t slr,
					       boost::uint32_t dlr,
					       m3ua_context m3ua)
{
    this->id = id;
    this->slr = slr;
    this->dlr = dlr;    
    this->m3ua = m3ua;
}


sccp_context::sccp_context(void)
{
    this->id = 0;
    this->slr = 0;
    this->dlr = 0;    
    memset(&this->m3ua, 0, sizeof(this->m3ua));
}


void sccp_context::sccp_context::set_id(boost::uint16_t id) 
{
    this->id = id;
}

void sccp_context::sccp_context::set_slr(boost::uint32_t slr) 
{
    this->slr = slr;
}

void sccp_context::sccp_context::set_dlr(boost::uint32_t dlr) 
{
    this->dlr = dlr;
}

void sccp_context::set_m3ua_context(m3ua_context m3ua)
{
    this->m3ua = m3ua;
}

boost::uint16_t sccp_context::get_id(void) const
{
    return this->id;
}

boost::uint32_t sccp_context::get_slr(void) const
{
    return this->slr;
}

boost::uint32_t sccp_context::get_dlr(void) const
{
    return this->dlr;
}

m3ua_context sccp_context::get_m3ua_context(void) const
{
    return this->m3ua;
}

std::size_t sccp_context::get_hash(void) const
{
	std::size_t h1;
	std::size_t h2;
	std::size_t h3;
	std::size_t h4;
	
	h1 = std::hash<int>{}(this->id);
	h2 = std::hash<int>{}(this->slr);
	h3 = std::hash<int>{}(this->dlr);
	h4 = this->m3ua.get_hash();
	
    return (h1 ^ (h2 << 1) ^ (h3 << 3) ^ (h4 << 4));
}

bool sccp_context::operator==(const sccp_context &rhs) const
{ 
    return ((this->get_id() == rhs.get_id())
    	&&  (this->get_slr() == rhs.get_slr())
    	&&  (this->get_dlr() == rhs.get_dlr())
        &&  (this->m3ua == rhs.m3ua));
}

void sccp_context::print() const
{
    cout << "SCCP Id:" << this->id << "\n";
    cout << "SCCP SLR:" << this->slr << "\n";
    cout << "SCCP DLR:" << this->dlr << "\n";
    this->m3ua.print();
}
