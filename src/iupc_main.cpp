// Simple IuPC 
#include <iostream> 
#include <context_db/iupc_context.hpp>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std; 

int main() 
{ 
   struct sockaddr_in addr1,addr2,addr3;
 
   addr1.sin_family = AF_INET;
   addr1.sin_addr.s_addr = inet_addr("10.0.0.1");
   addr1.sin_port = 0; 

   addr2.sin_family = AF_INET;
   addr2.sin_addr.s_addr = inet_addr("10.0.0.2");
   addr2.sin_port = 0; 
   
   addr3.sin_family = AF_INET;
   addr3.sin_addr.s_addr = inet_addr("10.0.0.3");
   addr3.sin_port = 0; 
   
   pcap_procedure pp1(1,2,3);
   pcap_procedure pp2(3,4,6);
   pcap_procedure pp3(4,5,8);
   
   pcap_context p1(1, sccp_context(1,2,3,m3ua_context(1, sctp_context(2,3,addr1))));
   pcap_context p2(2, sccp_context(3,4,5,m3ua_context(2, sctp_context(3,4,addr2))));
   pcap_context p3(3, sccp_context(4,5,6,m3ua_context(3, sctp_context(4,5,addr3))));

   context_db cdb;

   cdb.add(p1, pp1);
   cdb.add(p2, pp2);

   if (cdb.check(p1) == true) {
    pcap_procedure pp;
    pp=cdb.get_value(p1);
    p1.print();
    pp.print();
    cout << "\n-----\n";
   }

   if (cdb.check(p2) == true) {
    pcap_procedure pp;
    pp=cdb.get_value(p2);
    p2.print();
    pp.print();
    cout << "\n-----\n";
   }

   if (cdb.check(p3) == true) {
    pcap_procedure pp;
    pp=cdb.get_value(p3);
    p2.print();
    pp.print();
    cout << "\n-----\n";
   }
}

