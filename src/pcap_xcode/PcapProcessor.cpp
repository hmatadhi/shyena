


#include <iostream> 
#include <string.h>

#include "PCAP-CommonDataTypes.h"
#include "PCAP-PDU-Contents.h"
#include "PCAP-PDU-Descriptions.h"
#include "PCAP-Constants.h"

#include "Pcap.hpp"
#include "context_db/PcapContext.hpp"
#include "pcap_xcode/PcapPDU.hpp"
#include "pcap_xcode/PcapProcessor.hpp"
#include "pcap_xcode/internal/MessageBuffer.hpp"

#define LogError cout
#define LogDebug cout

using namespace std; 

pcap_processor::pcap_processor(void *pAsnPdu, PcapContextPtrType pCtxt, const PcapPDU *pPcapPDU)
{
    this->pAsnPdu = pAsnPdu;
    this->pCtxt = pCtxt;
    this->pPcapPDU = pPcapPDU;
} 

pcap_processor::~pcap_processor(void)
{
    return;
} 

PCAP_RC pcap_processor::ProcessDecodedPdu( 
                          boost::int32_t PduType, 
                          boost::uint8_t ProcedureCode) const
{
    PCAP_RC pcapRc = PCAP_RC_ERROR;

    switch(PduType)
    {
        case T_PCAP_PDU_initiatingMessage:
            switch(ProcedureCode)
            {
                case ASN1V_id_PositionInitiation:
                    /* Handle the Position Initiation Request */
                    pcapRc = HandlePositionInitiationRequest(this->pAsnPdu, this->pCtxt);
                    break;
                case ASN1V_id_PositionActivation:
                    /*  Handle the Position Activation Request */
                    pcapRc = HandlePositionActivationRequest(this->pAsnPdu, this->pCtxt);
                    break;
                case ASN1V_id_Abort:
                    /* Handle Position Abort */
                    pcapRc = HandlePositionAbort(this->pAsnPdu, this->pCtxt);
                    break;
                default:
                    LogError << "Unsupported Initiating message. Procedure Code: " << ProcedureCode;
                    break;
            }
            break;
        case T_PCAP_PDU_successfulOutcome:
            switch(ProcedureCode)
            {
                case ASN1V_id_PositionInitiation:
                    /* Handle the Position Initiation Response */
                    pcapRc = HandlePositionInitiationResponse(this->pAsnPdu, this->pCtxt);
                    break;
                case ASN1V_id_PositionActivation:
                    /* Handle the Position Activation Response */
                    pcapRc = HandlePositionActivationResponse(this->pAsnPdu, this->pCtxt);
                    break;                        
                default:
                    LogError << "Unsupported Successful outcome message. Procedure Code: " << ProcedureCode;
                    break;
            }
            break;
        case T_PCAP_PDU_unsuccessfulOutcome:
            switch(ProcedureCode)
            {
                case ASN1V_id_PositionInitiation:
                    /* Hanlde Location Error Response */
                    pcapRc = HandlePositionInitiationError(this->pAsnPdu, this->pCtxt);
                    break;
                case ASN1V_id_PositionActivation:
                    /* Handle the Position Activation Response */
                    pcapRc = HandlePositionActivationError(this->pAsnPdu, this->pCtxt);
                    break;                                               
                default:
                    LogError << "Unsupported un-successful outcome message. Procedure Code: " << ProcedureCode;
                    break;
            }
            break;
        default:
            LogError << "Unsupported PDU Type" << PduType;
            break;
    }
    return pcapRc;
}


PCAP_RC pcap_processor::EncapPcapPdu(boost::int32_t, boost::uint8_t) const
{

    return PCAP_RC_OK;
} 

/* requests */
PCAP_RC pcap_processor::HandlePositionInitiationRequest(void *pPdu, PcapContextPtrType pCtxt)  const
{
    pcap::ASN1T_PositionInitiationRequest pcapArg = *(static_cast<pcap::ASN1T_PositionInitiationRequest *>(pPdu));

    /* decode PI request, add members to context db; push context to task queue */    
    return PCAP_RC_OK;
}

PCAP_RC pcap_processor::HandlePositionActivationRequest(void *pPdu, PcapContextPtrType pCtxt)  const
{
    pcap::ASN1T_PositionActivationRequest pcapArg = *(static_cast<pcap::ASN1T_PositionActivationRequest *>(pPdu));
    /* decode PA request, add members to context db; push context to task queue */ 
    return PCAP_RC_OK;
}

PCAP_RC pcap_processor::HandlePositionAbort(void *pPdu, PcapContextPtrType pCtxt)  const
{   
    pcap::ASN1T_Abort pcapAbortPdu = *(static_cast<pcap::ASN1T_Abort *>(pPdu));

    PcapAbort pAbrt(*(this->pPcapPDU));

    ExtractPositionAbortData(pAbrt,pcapAbortPdu);    
    /* decode Abort request, tremove members from queues, stop processing, remobe context from context db */ 
    return PCAP_RC_OK;
}


/* successful responses */
PCAP_RC pcap_processor::HandlePositionInitiationResponse(void *pPdu, PcapContextPtrType pCtxt)  const
{
    pcap::ASN1T_PositionInitiationResponse pcapArg = *(static_cast<pcap::ASN1T_PositionInitiationResponse *>(pPdu));
    /* decode PI response, add members to context db; push context to task queue */ 
    return PCAP_RC_OK;
}

PCAP_RC pcap_processor::HandlePositionActivationResponse(void *pPdu, PcapContextPtrType pCtxt)  const
{
    pcap::ASN1T_PositionActivationResponse pcapArg = *(static_cast<pcap::ASN1T_PositionActivationResponse *>(pPdu));
    /* decode PA response, add members to context db; push context to task queue */ 
    return PCAP_RC_OK;
}


/* failure responses */
PCAP_RC pcap_processor::HandlePositionInitiationError(void *pPdu, PcapContextPtrType pCtxt)  const
{
    pcap::ASN1T_PositionInitiationFailure pcapArg = *(static_cast<pcap::ASN1T_PositionInitiationFailure *>(pPdu));
    /* decode PI Failure, stop  processing*/ 
    return PCAP_RC_OK;
}

PCAP_RC pcap_processor::HandlePositionActivationError(void *pPdu, PcapContextPtrType pCtxt)  const
{
    pcap::ASN1T_PositionActivationFailure pcapArg = *(static_cast<pcap::ASN1T_PositionActivationFailure *>(pPdu));
    /* decode PI Failure, stop  processing*/ 
    return PCAP_RC_OK;
}

void pcap_processor::ExtractPositionAbortData
(
    PcapAbort & pcapAbortArg,
    pcap::ASN1T_Abort& PcapAbortRequesteArg
) const
{   
    pcap::ASN1C_Abort_protocolIEs ProtoIEs(PcapAbortRequesteArg.protocolIEs);

    ASN1CSeqOfListIterator * It = ProtoIEs.iterator();
    pcap::ASN1T_Abort_protocolIEs_element *pElem =
        static_cast<pcap::ASN1T_Abort_protocolIEs_element *>
        (
            It->next()
        );

    while(pElem)
    {
        switch(pElem->id)
        {           
            case ASN1V_id_Cause:
                pcapAbortArg.aPcapCause.t = 
                    (static_cast<pcap::ASN1T_Cause*>(pElem->value.decoded))->t;
                switch(pcapAbortArg.aPcapCause.t)
                {
                    case T_Cause_radioNetwork:
                           pcapAbortArg.aPcapCause.u.radioNetwork = 
                                (static_cast<pcap::ASN1T_Cause*>(pElem->value.decoded)->u.radioNetwork);
                           break;
                    case T_Cause_transport:
                           pcapAbortArg.aPcapCause.u.transport = 
                                (static_cast<pcap::ASN1T_Cause*>(pElem->value.decoded)->u.transport);
                           break;
                    case T_Cause_protocol:
                           pcapAbortArg.aPcapCause.u.protocol = 
                                (static_cast<pcap::ASN1T_Cause*>(pElem->value.decoded)->u.protocol);
                           break;
                    case T_Cause_misc:
                           pcapAbortArg.aPcapCause.u.misc = 
                                (static_cast<pcap::ASN1T_Cause*>(pElem->value.decoded)->u.misc);
                           break;
                    case T_Cause_extElem1:
                            LogDebug << "External IE Element not supported";
                            break;                           
                    default:
                            LogDebug << "Invalid value for pcap Abort-Cause union Value";
                            break;
                }
                break;
            default:
                LogDebug << "PCAP Request: Skipping elem with Id: " << pElem->id;
                break;
        }

        if (It->hasNext())
        {
            pElem =
                static_cast<pcap::ASN1T_Abort_protocolIEs_element *>
                (
                    It->next()
                );
            continue;
        }        
        break;
    }    
}
