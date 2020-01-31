#include <iostream> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <context_db/SasContext.hpp>
#include <ut/UT_SASMain.hpp>
#include <layer_management/PcapLogger.hpp>

int UT_SAS::testContextDb() 
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
 
   SccpContext sccpContext1 = SccpContext(1,2,3,M3uaContext(1, SctpContext(2,3,addr1)));
   SccpContext sccpContext2 = SccpContext(1,2,3,M3uaContext(2, SctpContext(2,3,addr1)));
   SccpContext sccpContext3 = SccpContext(1,2,3,M3uaContext(3, SctpContext(2,3,addr1)));
  
   PcapProcedure pp1(1);
   PcapProcedure pp2(2);
   PcapProcedure pp3(3);
   
   PcapContext p1(1, sccpContext1);
   PcapContext p2(2, sccpContext2);
   PcapContext p3(3, sccpContext3);

   PcapProcedure pp4(4);
   PcapProcedure pp5(5);
   PcapProcedure pp6(6);
  

   PcapContext x1(1, SccpContext(3,4,5,M3uaContext(1, SctpContext(2,3,addr2))));
   PcapContext x2(2, SccpContext(3,4,5,M3uaContext(2, SctpContext(3,4,addr2))));
   PcapContext x3(3, SccpContext(3,4,5,M3uaContext(3, SctpContext(4,5,addr2))));

   PcapProcedure pp7(7);
   PcapProcedure pp8(8);
   PcapProcedure pp9(9);
  
   PcapContext y1(1, SccpContext(6,7,8,M3uaContext(1, SctpContext(2,3,addr3))));
   PcapContext y2(2, SccpContext(6,7,8,M3uaContext(2, SctpContext(3,4,addr3))));
   PcapContext y3(3, SccpContext(6,7,8,M3uaContext(3, SctpContext(4,5,addr3))));

   ContextDb cdb;

   cdb.addProcedure(p1, pp1);
   cdb.addProcedure(p2, pp2);
   cdb.addProcedure(p3, pp3);

   cdb.addProcedure(x1, pp4);
   cdb.addProcedure(x2, pp5);
   cdb.addProcedure(x3, pp6);

   cdb.addProcedure(y1, pp7);
   cdb.addProcedure(y2, pp8);
   cdb.addProcedure(y3, pp9);

/*
   if (cdb.checkKey(p1) == true) {
    PcapProcedure pp;
    pp=cdb.getValue(p1);
    p1.print();
    pp.print();
    std::cout << "\n-----\n";
   }

   if (cdb.checkKey(p2) == true) {
    PcapProcedure pp;
    pp=cdb.getValue(p2);
    p2.print();
    pp.print();
    std::cout << "\n-----\n";
   }

   if (cdb.checkKey(p3) == true) {
    PcapProcedure pp;
    pp=cdb.getValue(p3);
    p2.print();
    pp.print();
    std::cout << "\n-----\n";
   }
*/

 /*  
   if (cdb.checkKey(x1) == true) {
    PcapProcedure pp;
    pp=cdb.getValue(x1);
    x1.print();
    pp.print();
    std::cout << "\n-----\n";
   }

   if (cdb.checkKey(x2) == true) {
    PcapProcedure pp;
    pp=cdb.getValue(x2);
    x2.print();
    pp.print();
    std::cout << "\n-----\n";
   }

   if (cdb.checkKey(x3) == true) {
    PcapProcedure pp;
    pp=cdb.getValue(x3);
    x3.print();
    pp.print();
    std::cout << "\n-----\n";
   }

   if (cdb.checkKey(y1) == true) {
    PcapProcedure pp;
    pp=cdb.getValue(y1);
    y1.print();
    pp.print();
    std::cout << "\n-----\n";
   }

   if (cdb.checkKey(y2) == true) {
    PcapProcedure pp;
    pp=cdb.getValue(y2);
    y2.print();
    pp.print();
    std::cout << "\n-----\n";
   }

   if (cdb.checkKey(y3) == true) {
    PcapProcedure pp;
    pp=cdb.getValue(y3);
    y3.print();
    pp.print();
    std::cout << "\n-----\n";
   }
*/
   cout << "Loop through Session" << endl;
   vector<PcapProcedure> vecPcapProc;

   vecPcapProc = cdb.getSessionProceduures(p1.getSccpContext());

     for(vector<PcapProcedure>::iterator it = vecPcapProc.begin(); it != vecPcapProc.end(); it++) {
         PcapProcedure pp = *it;
         pp.print();
         LogDebug << "Looping through Session" << endl;
     }
    return 0;   

}


