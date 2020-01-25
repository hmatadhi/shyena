


#include <iostream> 
#include <string.h>

#include "PCAP-CommonDataTypes.h"
#include "PCAP-PDU-Contents.h"
#include "PCAP-PDU-Descriptions.h"
#include "PCAP-Constants.h"

#include "pcap.hpp"
#include "context_db/pcap_context.hpp"
#include "pcap_xcode/pcap_pdu.hpp"
#include "pcap_xcode/pcap_processor.hpp"
#include "pcap_xcode/MessageHelpers/MessageBuffer.hpp"

#define LogError cout

using namespace std; 

pcap_processor::pcap_processor(void *pPdu, PcapContextPtrType pCtxt)
{
    this->pPdu = pPdu;
    this->pCtxt = pCtxt;
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
                    pcapRc = HandlePositionInitiationRequest(this->pPdu, this->pCtxt);
                    break;
                case ASN1V_id_PositionActivation:
                    /*  Handle the Position Activation Request */
                    pcapRc = HandlePositionActivationRequest(this->pPdu, this->pCtxt);
                    break;
                case ASN1V_id_Abort:
                    /* Handle Position Abort */
                    pcapRc = HandlePositionAbort(this->pPdu, this->pCtxt);
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
                    pcapRc = HandlePositionInitiationResponse(this->pPdu, this->pCtxt);
                    break;
                case ASN1V_id_PositionActivation:
                    /* Handle the Position Activation Response */
                    pcapRc = HandlePositionActivationResponse(this->pPdu, this->pCtxt);
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
                    pcapRc = HandlePositionInitiationError(this->pPdu, this->pCtxt);
                    break;
                case ASN1V_id_PositionActivation:
                    /* Handle the Position Activation Response */
                    pcapRc = HandlePositionActivationError(this->pPdu, this->pCtxt);
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


PCAP_RC pcap_processor::HandlePositionInitiationRequest(void *pPdu, PcapContextPtrType pCtxt)  const
{
    //pcap::ASN1T_PCAP_PDU pcapArg = *(static_cast<pcap::ASN1T_PCAP_PDU *>(pPduArg))    
    return PCAP_RC_OK;
}

PCAP_RC pcap_processor::HandlePositionAbort(void *pPdu, PcapContextPtrType pCtxt)  const
{   
    return PCAP_RC_OK;
}

PCAP_RC pcap_processor::HandlePositionActivationRequest(void *pPdu, PcapContextPtrType pCtxt)  const
{
    return PCAP_RC_OK;
}

PCAP_RC pcap_processor::HandlePositionInitiationResponse(void *pPdu, PcapContextPtrType pCtxt)  const
{
    return PCAP_RC_OK;
}

PCAP_RC pcap_processor::HandlePositionActivationResponse(void *pPdu, PcapContextPtrType pCtxt)  const
{
    return PCAP_RC_OK;
}

PCAP_RC pcap_processor::HandlePositionInitiationError(void *pPdu, PcapContextPtrType pCtxt)  const
{
    return PCAP_RC_OK;
}

PCAP_RC pcap_processor::HandlePositionActivationError(void *pPdu, PcapContextPtrType pCtxt)  const
{
    return PCAP_RC_OK;
}
