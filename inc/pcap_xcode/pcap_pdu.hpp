#ifndef _PCAP_PDU_
#define _PCAP_PDU_

#include <stdint.h>
#include <string.h>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "context_db/pcap_context.hpp"
#include "pcap_xcode/MessageHelpers/MessageBuffer.hpp"
#include "pcap.hpp"

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
        boost::shared_ptr<pcap_context> pLteCtxtArg
    );

    explicit PcapPDU
    (
        boost::shared_ptr<MessageBufferType>    pBufferArg,
        boost::shared_ptr<pcap_context> pLteCtxtArg
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
    void SetContext(boost::shared_ptr<pcap_context> pcapCtxtArg);


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

    boost::shared_ptr<pcap_context> GetContext() const;

    boost::shared_ptr<MessageBufferType> GetMessageBuffer() const; 
protected:

    boost::shared_ptr<MessageBufferType>    apMessageBuffer;
    boost::shared_ptr<pcap_context>         apCtxt;
    PCAP_RC ProcessMessage() const;
};

typedef boost::shared_ptr<PcapPDU>   PcapPDUSharedPtrType;



class pi_request :  public PcapPDU {

    public: 
        pi_request(void);

        virtual  ~pi_request(void);

        int decode() const;
        int encode() const;
        void print() const;

};

class pi_response :  public PcapPDU {

    public: 
        pi_response(void);

        virtual  ~pi_response(void);

        int decode() const;
        int encode() const;
        void print() const;

};

class pa_request :  public PcapPDU {

    public: 
        pa_request(void);

        virtual  ~pa_request(void);

        int decode() const;
        int encode() const;
        void print() const;

};

class pa_response :  public PcapPDU {

    public: 
        pa_response(void);

        virtual  ~pa_response(void);

        int decode() const;
        int encode() const;
        void print() const;

};

class pcap_abort :  public PcapPDU {

    public: 
        pcap_abort(void);

        virtual  ~pcap_abort(void);

        int decode() const;
        int encode() const;
        void print() const;

};

typedef boost::shared_ptr<PcapPDU> PcapPduPtrType;




#endif
