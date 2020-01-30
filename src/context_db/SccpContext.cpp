#include <iostream>   
#include <context_db/SccpContext.hpp>
#include <context_db/M3uaContext.hpp>
#include <string.h>    

using namespace std;

SccpContext::SccpContext(boost::uint16_t id,
					       boost::uint32_t slr,
					       boost::uint32_t dlr,
					       M3uaContext m3ua)
{
    this->id = id;
    this->slr = slr;
    this->dlr = dlr;    
    this->m3ua = m3ua;
}


SccpContext::SccpContext(void)
{
    this->id = 0;
    this->slr = 0;
    this->dlr = 0;    
    memset(&this->m3ua, 0, sizeof(this->m3ua));
}


void SccpContext::SccpContext::setId(boost::uint16_t id) 
{
    this->id = id;
}

void SccpContext::SccpContext::setSLR(boost::uint32_t slr) 
{
    this->slr = slr;
}

void SccpContext::SccpContext::setDLR(boost::uint32_t dlr) 
{
    this->dlr = dlr;
}

void SccpContext::setM3uaContext(M3uaContext m3ua)
{
    this->m3ua = m3ua;
}

boost::uint16_t SccpContext::getId(void) const
{
    return this->id;
}

boost::uint32_t SccpContext::getSLR(void) const
{
    return this->slr;
}

boost::uint32_t SccpContext::getDLR(void) const
{
    return this->dlr;
}

M3uaContext SccpContext::getM3uaContext(void) const
{
    return this->m3ua;
}

std::size_t SccpContext::getHash(void) const
{
	std::size_t h1;
	std::size_t h2;
	std::size_t h3;
	std::size_t h4;
	
	h1 = std::hash<int>{}(this->id);
	h2 = std::hash<int>{}(this->slr);
	h3 = std::hash<int>{}(this->dlr);
	h4 = this->m3ua.getHash();
	
    return (h1 ^ (h2 << 1) ^ (h3 << 3) ^ (h4 << 4));
}

std::size_t SccpContext::getSessionHash(void) const
{
    std::size_t h1;
    std::size_t h2;
    std::size_t h3;
    std::size_t h4;

    h1 = std::hash<int>{}(this->id);
    h2 = std::hash<int>{}(this->slr);
    h3 = std::hash<int>{}(this->dlr);
    h4 = (h1 ^ (h2 << 1) ^ (h3 << 3));
    //cout << "[" << this->id << "," << this->slr << "," << this->dlr << "]" << " Session Hash:" << h4 << endl;
    return h4;
}

bool SccpContext::operator==(const SccpContext &rhs) const
{ 
    /* Only compare SCCP SLR/DLR and ID.
        Ignore M3UA and SCTP params 
     */   
    return ((this->getId() == rhs.getId())
    	&&  (this->getSLR() == rhs.getSLR())
    	&&  (this->getDLR() == rhs.getDLR()));
        //&&  (this->m3ua == rhs.m3ua));
}

void SccpContext::print() const
{
    cout << "SCCP Id:" << this->id << "\n";
    cout << "SCCP SLR:" << this->slr << "\n";
    cout << "SCCP DLR:" << this->dlr << "\n";
    this->m3ua.print();
}



std::string SccpContext::getString() const
{

    std::string sccpStr = "[SCCP Id:" + std::to_string(this->id) +
                     " SCCP SLR:" + std::to_string(this->slr) +  
                     " SCCP DLR:" + std::to_string(this->dlr) + "]";
         
    return sccpStr;
}
