#include <iostream>   
#include <context_db/m3ua_context.hpp>
#include <context_db/sctp_context.hpp>
#include <string.h>

using namespace std;


m3ua_context::m3ua_context(void)
{
    this->app_cp = 0;
    memset(&this->sctp, 0, sizeof(this->sctp));
}

m3ua_context::m3ua_context(boost::uint32_t app_cp, sctp_context sctp)
{
    this->app_cp = app_cp;
    this->sctp = sctp;
}

void m3ua_context::set_app_cp(boost::uint32_t id) 
{
    this->app_cp = app_cp;
}

void m3ua_context::set_sctp_context(sctp_context sctp)
{
    this->sctp = sctp;
}

boost::uint32_t m3ua_context::get_app_cp(void) const
{
    return this->app_cp;
}

sctp_context m3ua_context::get_sctp_context(void) const
{
    return this->sctp;
}

std::size_t m3ua_context::get_hash(void) const
{
	std::size_t h1;
	std::size_t h2;

	h1 = std::hash<int>{}(this->app_cp);
	h2 = this->sctp.get_hash();

    return (h1 ^ (h2 << 1));
}

bool m3ua_context::operator==(const m3ua_context &rhs) const
{ 
    return ((this->get_app_cp() == rhs.get_app_cp())
        &&  (this->sctp == rhs.sctp));
}

void m3ua_context::print() const
{
    cout << "M3UA App Cp:" << this->app_cp << "\n";
    this->sctp.print();
}
