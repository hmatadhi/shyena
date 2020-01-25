/**
 * @file ErrorCode.hpp
 *
 * @brief all application error codes go here
 *
 * © 2018 Tarsha Systems Co.
 * All rights reserved
 * See the license file which came with this software for more details
 *
 */

#ifndef ERROR_CODE_HPP
#define ERROR_CODE_HPP

typedef enum
{
    ErrorCode_Ok,
    ErrorCode_GenericFailure,
    ErrorCode_SctpConnectFailed,
    ErrorCode_SctpListenFailed,
    ErrorCode_SctpCloseFailed,
    ErrorCode_SctpSendFailed,
    ErrorCode_SctpSentPartData,
    ErrorCode_TxQueueFull
} ErrorCode;
#endif /* ERROR_CODE_HPP */
