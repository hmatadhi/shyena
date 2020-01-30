#ifndef _PCAP_H_
#define _PCAP_H_ 

typedef enum
{
    ErrorCode_Ok,
    ErrorCode_GenericFailure,
    /* PCAP Errors */
    ErrorCode_PcapEncodeFailure,
    ErrorCode_PcapDecodeFailure,
    /* SCCP Errors */
    ErrorCode_SessionFailure,
    /* SCTP Errors */
    ErrorCode_SctpConnectFailed,
    ErrorCode_SctpListenFailed,
    ErrorCode_SctpCloseFailed,
    ErrorCode_SctpSendFailed,
    ErrorCode_SctpSentPartData,
    /* Queuing Errors */
    ErrorCode_TxQueueFull
} ErrorCode;


typedef enum
{
    PCAP_RC_OK,
    PCAP_RC_ERROR
} PCAP_RC;

#endif