#include <iostream>   
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <context_db/SctpContext.hpp>


SctpContext::SctpContext(void)
{
    this->stream_id = 0;
    this->assoc_id = 0;
    memset(&this->sctp_addr, 0, sizeof(this->sctp_addr));
}

SctpContext::SctpContext(boost::uint16_t stream_id, 
	                       boost::uint16_t assoc_id,
						   struct sockaddr_in sctp_addr)
{
    this->stream_id = stream_id;
    this->assoc_id = assoc_id;
    this->sctp_addr = sctp_addr;
}

void SctpContext::setStreamId(boost::uint16_t stream_id) 
{
    this->stream_id = stream_id;
}

void SctpContext::setAssocId(boost::uint16_t assoc_id)
{
    this->assoc_id = assoc_id;
}

void SctpContext::setSctpAddr(struct sockaddr_in sctp_addr)
{
    this->sctp_addr = sctp_addr;
}

boost::uint16_t SctpContext::getStreamId(void) const
{
    return this->stream_id;
}

boost::uint16_t SctpContext::getAssocId(void) const
{
    return this->assoc_id;
}

struct sockaddr_in SctpContext::getSctpAddr(void) const
{
    return this->sctp_addr;
}

std::size_t SctpContext::getHash(void) const 
{
	std::size_t h1;
	std::size_t h2;
	std::size_t h3;
	h1 = std::hash<int>{}(this->sctp_addr.sin_addr.s_addr);
	h1 ^= std::hash<int>{}(this->sctp_addr.sin_port);
	h2 = std::hash<int>{}(this->assoc_id);
	h3 = std::hash<int>{}(this->stream_id);
	
    return (h1 ^ (h2 << 1) ^ (h3 << 3));
}

bool SctpContext::operator==(const SctpContext &rhs) const
{ 
    return ((this->getStreamId() == rhs.getStreamId())
    	&&  (this->getAssocId() == rhs.getAssocId())
    	&&  (this->getSctpAddr().sin_addr.s_addr == 
    		rhs.getSctpAddr().sin_addr.s_addr)
    	&&  (this->getSctpAddr().sin_port == 
    		rhs.getSctpAddr().sin_port));
}

void SctpContext::print() const
{
	struct in_addr ipAddr;
	
    std::cout << "SCTP stream_id:" << this->stream_id << "\n";
    std::cout << "SCTP assoc_id:" << this->assoc_id << "\n";
    memcpy(&ipAddr, &this->sctp_addr.sin_addr.s_addr, sizeof(ipAddr));
    std::cout << "SCTP sctp_addr:" 
         <<  inet_ntoa(ipAddr) << ":"
         <<  this->sctp_addr.sin_port <<"\n";
}
