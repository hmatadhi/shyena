#ifndef PCAP_MESSAGE_BUILDER_HPP
#define PCAP_MESSAGE_BUILDER_HPP
#if 0
#include "rtpersrc/asn1PerCppTypes.h"
#include <boost/smart_ptr/shared_ptr.hpp>
#include "context_db/pcap_context.hpp"
//#include "Logger.hpp"
#include "pcap_xcode/MessageHelpers/MessageBuffer.hpp"

//#define LogError cout
//#define LogDebug cout

template <typename T, typename C>
class PcapMessageBuilderType
{
public:
    explicit PcapMessageBuilderType
    (
        //boost::shared_ptr<pcap_context> pCtxtArg,
        const bool DebugArg = false
    );

    virtual ~PcapMessageBuilderType() = 0;

    bool BuildMessage();

    const uint8_t * GetMsgPtr() { return aEncBuffer.getMsgPtr();}
    const uint32_t GetMsgLen() { return aEncBuffer.getMsgLen();}
    MessageBufferPtrType GetMessageBuffer();

private:
    bool Encode();

    virtual bool BuildPdu() = 0;

protected:
    inline OSCTXT * GetAsn1CtxtPtr() {return aEncoder.getCtxtPtr();}

protected:
    ASN1PEREncodeBuffer aEncBuffer;
    T aEncData;
    C aEncoder;

    boost::shared_ptr<pcap_context>   apCtxt;
private:
    const bool aDebug;
};

template<class T, class C>
PcapMessageBuilderType<T,C>::PcapMessageBuilderType
(
    //boost::shared_ptr<pcap_context> pCtxtArg,
    const bool DebugArg
)
    : aEncBuffer(TRUE)
    , aEncoder(aEncBuffer, aEncData)
    //, apCtxt(pCtxtArg)
    , aDebug(DebugArg)
{
   aEncBuffer.setTrace(DebugArg);
   aEncBuffer.setDiag(DebugArg);
}

template<class T, class C>
PcapMessageBuilderType<T,C>::~PcapMessageBuilderType()
{
}

template<class T, class C>
bool PcapMessageBuilderType<T, C>::Encode()
{
    int ret = aEncoder.Encode();
    if (ret < 0)
    {
        //LogError << "Encoding failed";
        //TODO:
        aEncBuffer.printErrorInfo();
        return false;
    }
    else
    {
        if (aDebug)
        {
            //LogDebug << "Encoding was successful";
            //LogDebug << "Hex dump of encoded record:";
            aEncBuffer.hexDump ();
            //LogDebug << "Binary dump:";
            aEncBuffer.binDump ("Data");
        }
    }
    return true;
}

template<class T, class C>
bool PcapMessageBuilderType<T, C>::BuildMessage()
{
    bool Ret = BuildPdu();

    if (!Ret)
    {
        //LogError << "Failed to build PDU";
        return NULL;
    }

    Ret = Encode();

    return Ret;
}

template<class T, class C>
MessageBufferPtrType PcapMessageBuilderType<T, C>::GetMessageBuffer()
{
    if (aEncBuffer.getMsgLen() && aEncBuffer.getMsgPtr())
    {
        return MessageBufferPtrType
               (
                    new MessageBufferType
                    (
                        aEncBuffer.getMsgPtr(),
                        aEncBuffer.getMsgLen()
                    )
                );
    }
    return NULL;
}
#endif
#endif /* PCAP_MESSAGE_BUILDER_HPP */
