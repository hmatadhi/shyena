#ifndef MESSAGEBUFFER_HPP
#define MESSAGEBUFFER_HPP
#include <sys/types.h>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <string.h>

struct MessageBufferType
{
    MessageBufferType() : pData(NULL), DataLen(0)
    {
    }

    MessageBufferType
    (
        const uint8_t   *pDataArg,
        uint32_t const  DataLenArg
    )
    {
        if (!pDataArg || !DataLenArg)
        {
            pData = NULL;
            DataLen = 0;
        }
        else
        {
            try
            {
                pData = new uint8_t[DataLenArg];
                memcpy(pData, pDataArg, DataLenArg);
                DataLen = DataLenArg;
            }
            catch(std::bad_alloc & ExceptionArg)
            {
                DataLen = 0;
            }
        }
    }

    ~MessageBufferType()
    {
        if (pData)
            delete[] pData;
    }

    uint8_t     *pData;
    uint32_t    DataLen;
};

typedef boost::shared_ptr<MessageBufferType> MessageBufferPtrType;
#endif
