#ifndef PCAP_MESSAGE_DECODER_BASE_HPP
#define PCAP_MESSAGE_DECODER_BASE_HPP

#include "PCAP-CommonDataTypes.h"
#include "PCAP-PDU-Contents.h"
#include "PCAP-PDU-Descriptions.h"
#include "pcap_xcode/MessageHelpers/PcapMessageDecoder.hpp"


class PcapMessageDecoderBaseType : public PcapMessageDecoderType<pcap::ASN1T_PCAP_PDU, pcap::ASN1C_PCAP_PDU>
{
public:
    PcapMessageDecoderBaseType(MessageBufferPtrType pMessageBufferArg, const bool DebugArg);
    ~PcapMessageDecoderBaseType(){};

	bool ExtractPduTypeAndProcedureCode(int32_t &PduTypeArg, uint8_t & ProcCodeArg, void ** ppPduArg);
};

#endif /* PCAP_MESSAGE_DECODER_BASE_HPP */
