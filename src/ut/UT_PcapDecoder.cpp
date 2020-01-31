#include <iostream> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
#include <context_db/SasContext.hpp>
#include <ut/UT_SASMain.hpp>
#include <layer_management/PcapLogger.hpp>


int UT_SAS::testDecode() 
{
    struct sockaddr_in addr1,addr2,addr3;

    addr1.sin_family = AF_INET;
    addr1.sin_addr.s_addr = inet_addr("10.0.0.1");
    addr1.sin_port = 0; 

    /* Initiation Request */
    uint8_t pu8bufinit[]  =  { 0x00, 0x09, 0x20, 0x05, 0x26, 0x27, 0x00, 0x00, 0x06, 0x00, 0x1c, 0x00, 0x02, 0x45, 0x14, 0x00,
                               0x1d, 0x00, 0x02, 0x24, 0x00, 0x00, 0x1e, 0x00, 0x05, 0x00, 0x03, 0xf7, 0x86, 0xed, 0x00, 0x1f,
                               0x40, 0x01, 0x00, 0x00, 0x20, 0x40, 0x01, 0x00, 0x00, 0x21, 0x40, 0x01, 0x30 };


    /* Activation Request */
    uint8_t pu8buf[]  =  {    0x00, 0x0a, 0x20, 0x00, 0x03, 0x16, 0x40, 0x00, 0x02, 0x00, 0x22, 0x00, 0x02, 0x01, 0x80, 0x00,
                             0x26, 0x40, 0x01, 0x00, 0x00, 0x00, 0x00, 0x42, 0x40, 0x02, 0x01, 0xe0 };

    //"\x00\x0a\x20\x00\x03\x16\x40\x00\x02\x00\x22\x00\x02\x01\x80\x00\x26\x40\x01\x00\x00\x00\x00\x42\x40\x02\x01\xe0";
    
    LogDebug << "Test Decoder size=" << sizeof(pu8buf);

    PcapContext x1(1, SccpContext(3,4,5,M3uaContext(1, SctpContext(2,3,addr1))));
    boost::shared_ptr<PcapContext>   x1Ptr(boost::make_shared<PcapContext>(x1));

    PcapPDU pcapPDU(pu8bufinit, sizeof(pu8bufinit), x1Ptr);

    LogDebug << " Before decode " << sizeof(pu8buf);

    pcapPDU.decode();

    return 0;

}