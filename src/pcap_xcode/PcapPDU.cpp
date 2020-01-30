

#include <iostream> 
#include <string.h>

#include "context_db/PcapContext.hpp"
#include "pcap_xcode/PcapPDU.hpp"
#include "pcap_xcode/PcapProcessor.hpp"
#include "pcap_xcode/internal/MessageBuffer.hpp"
#include "pcap_xcode/internal/PcapMessageDecoderBase.hpp"

PcapPDU::PcapPDU
(
    const uint8_t *pDataArg,
    const uint32_t DataLenArg,
    boost::shared_ptr<PcapContext> pcapCtxtArg
)
: apMessageBuffer(new MessageBufferType(pDataArg, DataLenArg))
, apCtxt(pcapCtxtArg)
{
}

PcapPDU::PcapPDU
(
    boost::shared_ptr<MessageBufferType>    pBufferArg,
    boost::shared_ptr<PcapContext> pcapCtxtArg
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
void PcapPDU::SetContext(boost::shared_ptr<PcapContext> pcapCtxtArg)
{
    apCtxt = pcapCtxtArg;
}

/* Function to set the context */
boost::shared_ptr<PcapContext> PcapPDU::GetContext() const
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
    std::cout << __FUNCTION__ << ":" << __LINE__ << "Parse ASN, Fill local IE elements" << "\n";
    return PCAP_RC_OK;
}

/* Function to encode the PDU to be sent */
PCAP_RC PcapPDU::encode() const
{
    /* ASN1 Encode */
    /* Set the local parameters for specific IEs */
    std::cout << __FUNCTION__ << ":" << __LINE__ << "Construct ASN, Fetch from local IE elements" << "\n";
    return PCAP_RC_OK;
}

void PcapPDU::print() const
{
    std::cout << "PCAP PDU Id:" <<  "\n";
}



/* Function to process the incoming PCAP message */
PCAP_RC PcapPDU::ProcessMessage() const
{
    PCAP_RC ProcessorStatus = PCAP_RC_ERROR;
    PcapMessageDecoderBaseType Decoder(this->GetMessageBuffer(), true);
    PcapContextPtrType pCtxt = this->GetContext();

    int32_t PduType;
    uint8_t ProcedureCode;

    void *pAsnPdu;


    /* Call the decoder to decode the message */
    const bool DecodeStatus = Decoder.ExtractPduTypeAndProcedureCode(PduType, ProcedureCode, &pAsnPdu);

    if (DecodeStatus) {
        
        pcap_processor pcapProcessor(pAsnPdu, pCtxt, this);

        ProcessorStatus  = pcapProcessor.ProcessDecodedPdu(PduType, ProcedureCode);
    }    
    return ProcessorStatus;


}
