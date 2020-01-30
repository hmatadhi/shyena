#if 0
#include "pcap_xcode/MessageHelpers/PcapAbortRequestBuilder.hpp"
#include "PCAP-Constants.h"
#include "PCAP-PDU-Contents.h"
#include "PCAP-PDU-Descriptions.h"
#include "PCAP-CommonDataTypes.h"
//#include "Logger.hpp"
#include "context_db/pcap_context.hpp"

//#define LogError cout


PcapAbortRequestBuilderType::PcapAbortRequestBuilderType(
  //boost::shared_ptr<pcap_context> pCtxtArg, 
  const bool DebugArg) :
    PcapMessageBuilderType(pCtxtArg, DebugArg)
{
}

PcapAbortRequestBuilderType::~PcapAbortRequestBuilderType()
{
}

pcap::ASN1T_Abort* PcapAbortRequestBuilderType::BuildLocAbortReq()
{
    using namespace pcap;

    ASN1T_Abort *pAbortReq
                      = (ASN1T_Abort *)rtxMemAllocZ(GetAsn1CtxtPtr(), sizeof(ASN1T_Abort));

    if(NULL == pAbortReq)
    {
        //LogError << "Memory allocation Failed : ASN1T_Abort ";
        return NULL;
    }

    // Add protocol IEs
    ASN1C_Abort_protocolIEs ProtocolIEs(aEncoder,pAbortReq->protocolIEs);

    ProtocolIEs.init();

    // Allocate element
    ASN1T_Abort_protocolIEs_element *pElement = ProtocolIEs.NewElement();
 
    if(NULL == pElement)
    {
        //LogError << "New Element Creation Failed for Locatin Abort Request: CorrelationID";
        return NULL;
    }

    // Initialize element
    if (asn1Init_Abort_protocolIEs_element(pElement,TRUE, GetAsn1CtxtPtr()) != 0)
    {
        //LogError << "initialization of location abort req proto ies element failed";
        return NULL;
    }

    // Populate element
    pElement->id = ASN1V_id_Cause;
    pElement->criticality = pcap::Criticality::reject;

    /* LCS Cause Value Id value is 4 Octet */
    ASN1T_Cause *pCause =
        (ASN1T_Cause*)rtxMemAllocZ(GetAsn1CtxtPtr(), sizeof(ASN1T_Cause));

    if (pCause != NULL)
    {
        asn1Init_Cause(pCause);
        pCause->t = T_Cause_protocol;
        pCause->u.protocol = CauseProtocol::transfer_syntax_error;

        pElement->value.decoded = pCause;
    }
    else
    {
        //LogError << "Failed to allocate ASN1T_LCS_Cause";
        return NULL;
    }

    ProtocolIEs.Append(pElement);

    return pAbortReq;
}


bool PcapAbortRequestBuilderType::BuildPdu()
{
    using namespace pcap;
    bool Ret = false;
    // Initialize encode data
    if (asn1Init_PCAP_PDU(&aEncData, TRUE, GetAsn1CtxtPtr()) != 0)
    {
        //LogError << "Failed to initialize LCS-AP PDU";
        return false;
    }

    aEncData.u.extElem1 = NULL;
    aEncData.t = T_PCAP_PDU_initiatingMessage;

    // Initiating Message
    ASN1T_InitiatingMessage *pInitiatingMsg =
        (ASN1T_InitiatingMessage*)rtxMemAllocZ(GetAsn1CtxtPtr(), sizeof(ASN1T_InitiatingMessage));

    if(NULL != pInitiatingMsg)
    {
        pInitiatingMsg->procedureCode = ASN1V_id_Abort;
        pInitiatingMsg->criticality = pcap::Criticality::reject;

        ASN1T_Abort *pLocAbortTree;
        pLocAbortTree = BuildLocAbortReq();
        if(NULL == pLocAbortTree)
        {
            //LogError << "Building Pcap Abort Request Failed";
            return false;
        }
        pInitiatingMsg->value.decoded = pLocAbortTree ;
    }
    else
    {
        //LogError << "Memory allocation for ANS1T_InitiatingMessage failed";
        return false;
    }
    aEncData.u.initiatingMessage = pInitiatingMsg;
    return true;
}
#endif
