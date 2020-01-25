#ifndef PCAP_MESSAGE_DECODER_HPP
#define PCAP_MESSAGE_DECODER_HPP

#include "rtpersrc/asn1PerCppTypes.h"
#include <boost/smart_ptr/shared_ptr.hpp>
#include "pcap_xcode/MessageHelpers/MessageBuffer.hpp"
#include <iostream>

template <typename T, typename C>
class PcapMessageDecoderType
{
public:
    explicit PcapMessageDecoderType
    (
        MessageBufferPtrType pMessageBufferArg,
        const bool DebugArg = false
    );

    virtual ~PcapMessageDecoderType() = 0;

protected:
    bool DecodeMessage();
    inline OSCTXT * GetAsn1CtxtPtr() {return aDecoder.getCtxtPtr();}

private:
    bool Decode();
    bool LoadBuffer();
    void LogBufferError();
    const T & GetDecodedData() const;

protected:
    ASN1PERDecodeBuffer aDecodeBuffer;
    T aDecData;
    C aDecoder;
    MessageBufferPtrType apMessageBuffer;
    const bool aDebug;
};

template<class T, class C>
PcapMessageDecoderType<T,C>::PcapMessageDecoderType
(
    MessageBufferPtrType pMessageBufferArg,
    const bool DebugArg
)
    : aDecodeBuffer(pMessageBufferArg ? pMessageBufferArg->pData : NULL,
                    pMessageBufferArg ? pMessageBufferArg->DataLen : 0,
                    TRUE)
    , aDecoder(aDecodeBuffer, aDecData)
    , apMessageBuffer(pMessageBufferArg)
    , aDebug(DebugArg)
{
   aDecodeBuffer.setTrace(DebugArg);
   aDecodeBuffer.setDiag(DebugArg);
}

template<class T, class C>
PcapMessageDecoderType<T,C>::~PcapMessageDecoderType()
{
}

template<class T, class C>
void PcapMessageDecoderType<T, C>::LogBufferError()
{
    char *pErrorMsg = aDecodeBuffer.getErrorInfo();
    if (pErrorMsg)
    {
        //cout << pErrorMsg;
        delete [] pErrorMsg;
    }
}

template<class T, class C>
bool PcapMessageDecoderType<T, C>::Decode()
{
    int ret = aDecoder.Decode();
    if (ret != 0)
    {
        LogBufferError();
        return false;
    }
    else
    {
        if (aDebug)
        {
            //cout << "Decoding was successful";
            //cout << "Dump of Decoded bitfields:";
            aDecodeBuffer.BinDump("Data");
            //cout << "";
        }
    }

    return true;
}

template<class T, class C>
bool PcapMessageDecoderType<T, C>::LoadBuffer()
{
    bool Ret = false;
    if (apMessageBuffer && aDecodeBuffer.getStatus() == 0)
    {
        Ret = true;
    }
    else if (aDecodeBuffer.getStatus())
    {
        LogBufferError();
    }

    return Ret;
}

template<class T, class C>
bool PcapMessageDecoderType<T, C>::DecodeMessage()
{
    bool Ret = LoadBuffer();

    if (Ret)
    {
        Ret = Decode();
    }

    return Ret;
}

template<class T, class C>
const T & PcapMessageDecoderType<T, C>::GetDecodedData() const
{
    return aDecData;
}

#endif /* PCAP_MESSAGE_DECODER_HPP */
