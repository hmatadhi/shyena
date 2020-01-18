// Simple IuPC 
#include <iostream> 
#include <context_db.hpp>
#include <pcap_context.hpp>
#include <pcap_procedure.hpp>

using namespace std; 

int main() 
{ 
   pcap_procedure pp1(1,2,3);
   pcap_procedure pp2(3,4,6);
   pcap_procedure pp3(4,5,8);

   pcap_context p1(1, 2);
   pcap_context p2(2, 3);
   pcap_context p3(3, 4);

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

