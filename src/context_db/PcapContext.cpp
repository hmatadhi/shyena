#include <iostream> 
#include <context_db/PcapContext.hpp>  
#include <context_db/SccpContext.hpp>
#include <string.h> 

PcapContext::PcapContext(void)
{
    this->tid = 0;
    memset(&this->sccp, 0, sizeof(this->sccp));
}

PcapContext::PcapContext(boost::uint32_t tid, SccpContext sccp)
{
    this->tid = tid;
    this->sccp = sccp;
}

void PcapContext::setTid(boost::uint32_t tid) 
{
    this->tid = tid;
}

void PcapContext::setSccpContext(SccpContext sccp)
{
    this->sccp = sccp;
}

boost::uint32_t PcapContext::getTid(void) const
{
    return this->tid;
}

SccpContext PcapContext::getSccpContext(void) const
{
    return this->sccp;
}


std::size_t PcapContext::getHash(void) const
{
	std::size_t h1;
	std::size_t h2;

	h1 = std::hash<int>{}(this->tid);
	h2 = this->sccp.getSessionHash();

    return (h1 ^ (h2 << 1));
}

bool PcapContext::operator==( const PcapContext &rhs) const
{ 
    return ((this->getTid() == rhs.getTid())
        &&  (this->sccp == rhs.sccp));
}

void PcapContext::print() const
{
    std::cout << "PCAP Transaction Id:" << this->tid << "\n";
    this->sccp.print();
}

std::string PcapContext::getString() const
{

    std::string pcapStr = "[PCAP Tid:" + std::to_string(this->tid) + "]";
         
    return pcapStr;
}