

#include <iostream> 
#include <string.h>

#include "context_db/pcap_context.hpp"
#include "context_db/pcap_procedure.hpp"
#include "pcap_xcode/pcap_pdu.hpp"
#include "pcap_xcode/pcap_processor.hpp"
#include "pcap_xcode/MessageHelpers/MessageBuffer.hpp"
#include "pcap_xcode/MessageHelpers/PcapMessageDecoderBase.hpp"

using namespace std; 

PcapPDU::PcapPDU
(
    const uint8_t *pDataArg,
    const uint32_t DataLenArg,
    boost::shared_ptr<pcap_context> pcapCtxtArg
)
: apMessageBuffer(new MessageBufferType(pDataArg, DataLenArg))
, apCtxt(pcapCtxtArg)
{
}

PcapPDU::PcapPDU
(
    boost::shared_ptr<MessageBufferType>    pBufferArg,
    boost::shared_ptr<pcap_context> pcapCtxtArg
)
: apMessageBuffer(pBufferArg)
, apCtxt(pcapCtxtArg)
{
}

PcapPDU::~PcapPDU()
{
}

/* function to get the data in the buffer */
const uint8_t * const PcapPDU::Data() const
{
    return apMessageBuffer->pData;
}

/* FUnction to get the DataLength of the buffer */
const uint32_t PcapPDU::DataLen() const
{
    return apMessageBuffer->DataLen;
}

/* Function to set the context */
void PcapPDU::SetContext(boost::shared_ptr<pcap_context> pcapCtxtArg)
{
    apCtxt = pcapCtxtArg;
}

/* Function to set the context */
boost::shared_ptr<pcap_context> PcapPDU::GetContext() const
{
    return this->apCtxt;
}

/* Function to get the buffer */
boost::shared_ptr<MessageBufferType> PcapPDU::GetMessageBuffer() const
{
    return this->apMessageBuffer;
}

/* Function to decode the received PDU */
PCAP_RC PcapPDU::decode() const
{
    /* ASN1 Decode */
    /* Set the local parameters for specific IEs */
    cout << __FUNCTION__ << ":" << __LINE__ << "Parse ASN, Fill local IE elements" << "\n";
    return PCAP_RC_OK;
}

/* Function to encode the PDU to be sent */
PCAP_RC PcapPDU::encode() const
{
    /* ASN1 Encode */
    /* Set the local parameters for specific IEs */
    cout << __FUNCTION__ << ":" << __LINE__ << "Construct ASN, Fetch from local IE elements" << "\n";
    return PCAP_RC_OK;
}

void PcapPDU::print() const
{
    cout << "PCAP PDU Id:" <<  "\n";
}



/* Function to process the incoming PCAP message */
PCAP_RC PcapPDU::ProcessMessage() const
{
    PCAP_RC ProcessorStatus = PCAP_RC_ERROR;
    PcapMessageDecoderBaseType Decoder(this->GetMessageBuffer(), true);
    PcapContextPtrType pCtxt = this->GetContext();

    int32_t PduType;
    uint8_t ProcedureCode;



    void *pPdu;


    /* Call the decoder to decode the message */
    const bool DecodeStatus = Decoder.ExtractPduTypeAndProcedureCode(PduType, ProcedureCode, &pPdu);

    if (DecodeStatus) {
        
        pcap_processor pcapProcessor(pPdu, pCtxt);

        ProcessorStatus  = pcapProcessor.ProcessDecodedPdu(PduType, ProcedureCode);
    }    
    return ProcessorStatus;


}
