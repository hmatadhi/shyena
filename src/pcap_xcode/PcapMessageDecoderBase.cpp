#include "PCAP-Constants.h"
#include "PCAP-PDU-ContentsTable.h"
#include "pcap_xcode/internal/PcapMessageDecoderBase.hpp"

#define LogDebug std::cout
#define LogWarning std::cout

PcapMessageDecoderBaseType::PcapMessageDecoderBaseType(MessageBufferPtrType pMessageBufferArg, const bool DebugArg)
    : PcapMessageDecoderType<pcap::ASN1T_PCAP_PDU, pcap::ASN1C_PCAP_PDU>(pMessageBufferArg, DebugArg)
{
}

bool PcapMessageDecoderBaseType::ExtractPduTypeAndProcedureCode(int32_t &PduTypeArg, uint8_t & ProcCodeArg, void ** ppPduArg)
{
    bool Ret = false;
    uint8_t ProcedureCode;
    bool ProcedureCodeFound = false, ProcedureCodeSupported = false;

    if (DecodeMessage())
    {
        switch (aDecData.t)
        {
            case T_PCAP_PDU_initiatingMessage:
                ProcedureCode = aDecData.u.initiatingMessage->procedureCode;
                ProcedureCodeFound = true;
                if(ASN1V_id_Abort == ProcedureCode ||
                    ASN1V_id_PositionInitiation == ProcedureCode ||
                        ASN1V_id_PositionActivation == ProcedureCode )
                {
                    *ppPduArg = aDecData.u.initiatingMessage->value.decoded;
                    ProcedureCodeSupported = true;
                }
                break;
            case T_PCAP_PDU_successfulOutcome:
                ProcedureCode = aDecData.u.successfulOutcome->procedureCode;
                ProcedureCodeFound = true;
                if(ASN1V_id_PositionInitiation == ProcedureCode ||
                    ASN1V_id_PositionActivation == ProcedureCode )
                {
                    *ppPduArg = aDecData.u.successfulOutcome->value.decoded;
                    ProcedureCodeSupported = true;
                }
                break;
            case T_PCAP_PDU_unsuccessfulOutcome:
                ProcedureCode = aDecData.u.unsuccessfulOutcome->procedureCode;
                ProcedureCodeFound = true;
                if(ASN1V_id_PositionInitiation == ProcedureCode ||
                    ASN1V_id_PositionActivation == ProcedureCode )
                {
                    *ppPduArg = aDecData.u.unsuccessfulOutcome->value.decoded;
                    ProcedureCodeSupported = true;
                }
                break;
            default:
                LogWarning << "Unhandled pdu type: " << aDecData.t;
                break;
        }

        if (ProcedureCodeSupported)
        {
            PduTypeArg = aDecData.t;
            ProcCodeArg = ProcedureCode;
            Ret = true;
            LogDebug << "Procedure Code [" << ProcedureCode << "]";
        }
    }
   
    return Ret;
}

