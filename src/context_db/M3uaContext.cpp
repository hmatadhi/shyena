#include <iostream>   
#include <context_db/M3uaContext.hpp>
#include <context_db/SctpContext.hpp>
#include <string.h>

M3uaContext::M3uaContext(void)
{
    this->app_cp = 0;
    memset(&this->sctp, 0, sizeof(this->sctp));
}

M3uaContext::M3uaContext(boost::uint32_t app_cp, SctpContext sctp)
{
    this->app_cp = app_cp;
    this->sctp = sctp;
}

void M3uaContext::setAppCP(boost::uint32_t id) 
{
    this->app_cp = app_cp;
}

void M3uaContext::setSctpContext(SctpContext sctp)
{
    this->sctp = sctp;
}

boost::uint32_t M3uaContext::getAppCP(void) const
{
    return this->app_cp;
}

SctpContext M3uaContext::getSctpContext(void) const
{
    return this->sctp;
}

std::size_t M3uaContext::getHash(void) const
{
	std::size_t h1;
	std::size_t h2;

	h1 = std::hash<int>{}(this->app_cp);
	h2 = this->sctp.getHash();

    return (h1 ^ (h2 << 1));
}

bool M3uaContext::operator==(const M3uaContext &rhs) const
{ 
    return ((this->getAppCP() == rhs.getAppCP())
        &&  (this->sctp == rhs.sctp));
}

void M3uaContext::print() const
{
    std::cout << "M3UA App Cp:" << this->app_cp << "\n";
    this->sctp.print();
}
