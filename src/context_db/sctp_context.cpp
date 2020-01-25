#include <iostream>   
#include <context_db/sctp_context.hpp>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


using namespace std;

sctp_context::sctp_context(void)
{
    this->stream_id = 0;
    this->assoc_id = 0;
    memset(&this->sctp_addr, 0, sizeof(this->sctp_addr));
}

sctp_context::sctp_context(boost::uint16_t stream_id, 
	                       boost::uint16_t assoc_id,
						   struct sockaddr_in sctp_addr)
{
    this->stream_id = stream_id;
    this->assoc_id = assoc_id;
    this->sctp_addr = sctp_addr;
}

void sctp_context::set_stream_id(boost::uint16_t stream_id) 
{
    this->stream_id = stream_id;
}

void sctp_context::set_assoc_id(boost::uint16_t assoc_id)
{
    this->assoc_id = assoc_id;
}

void sctp_context::set_sctp_addr(struct sockaddr_in sctp_addr)
{
    this->sctp_addr = sctp_addr;
}

boost::uint16_t sctp_context::get_stream_id(void) const
{
    return this->stream_id;
}

boost::uint16_t sctp_context::get_assoc_id(void) const
{
    return this->assoc_id;
}

struct sockaddr_in sctp_context::get_sctp_addr(void) const
{
    return this->sctp_addr;
}

std::size_t sctp_context::get_hash(void) const 
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

bool sctp_context::operator==(const sctp_context &rhs) const
{ 
    return ((this->get_stream_id() == rhs.get_stream_id())
    	&&  (this->get_assoc_id() == rhs.get_assoc_id())
    	&&  (this->get_sctp_addr().sin_addr.s_addr == 
    		rhs.get_sctp_addr().sin_addr.s_addr)
    	&&  (this->get_sctp_addr().sin_port == 
    		rhs.get_sctp_addr().sin_port));
}

void sctp_context::print() const
{
	struct in_addr ipAddr;
	
    cout << "SCTP stream_id:" << this->stream_id << "\n";
    cout << "SCTP assoc_id:" << this->assoc_id << "\n";
    memcpy(&ipAddr, &this->sctp_addr.sin_addr.s_addr, sizeof(ipAddr));
    cout << "SCTP sctp_addr:" 
         <<  inet_ntoa(ipAddr) << ":"
         <<  this->sctp_addr.sin_port <<"\n";
}
