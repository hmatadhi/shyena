#ifndef _PCAP_PDU_
#define _PCAP_PDU_

#include <stdint.h>
#include <string.h>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "context_db/PcapContext.hpp"
#include "pcap_xcode/internal/MessageBuffer.hpp"
#include "Pcap.hpp"
#include "PCAP-IEs.h"
/**
 * @class PcapPDU PcapPDU.hpp "inc/PcapPDU.hpp"
 * @brief PcapPDU class to hold the incoming/outgoing
 *        data.
 *
 */
class PcapPDU
{
public:
    /**
     * Construct #PcapPDU instance.
     *
     * @param[in]   pDataArg    pointer to the data to be copied
     * @param[in]   DataLenArg  length of the data to be copied
     *
     * The data is copied and can be freed by the caller once
     * the constructor returns.
     *
     */ 
    explicit PcapPDU
    (
        const uint8_t *pDataArg,
        const uint32_t DataLenArg,
        boost::shared_ptr<PcapContext> pPcapCtxtArg
    );

    explicit PcapPDU
    (
        boost::shared_ptr<MessageBufferType>    pBufferArg,
        boost::shared_ptr<PcapContext> pPcapCtxtArg
    );
    /**
     * Destructor of #PcapPDU class
     *
     */
    virtual ~PcapPDU();

    /**
     * Returns a pointer to the underlying data
     *
     * @return  byte pointer to the underlying data
     *
     */ 
    const uint8_t * const Data() const;

    /**
     * Returns the length of data in bytes
     *
     * @return byte length of the data buffer
     */
    const uint32_t DataLen() const;

    /**
     * Set the context for this lte message
     *
     * @param[in] pLteCtxtArg context pointer
     *
     */
    void SetContext(boost::shared_ptr<PcapContext> pcapCtxtArg);


    /**
     * Decode the PCAP PDU from buffer
     *
     * @param[in] None
     *
     */
    PCAP_RC decode() const;


    /**
     * Encode the PCAP PDU into buffer
     *
     * @param[in] None
     *
     */    
    PCAP_RC encode() const;
 
     /**
     * print function
     *
     * @param[in] None
     *
     */    
    void print() const;    

    boost::shared_ptr<PcapContext> GetContext() const;

    boost::shared_ptr<MessageBufferType> GetMessageBuffer() const; 
protected:

    boost::shared_ptr<MessageBufferType>    apMessageBuffer;
    boost::shared_ptr<PcapContext>         apCtxt;
    PCAP_RC ProcessMessage() const;
};

typedef boost::shared_ptr<PcapPDU> PcapPduPtrType;
#endif
