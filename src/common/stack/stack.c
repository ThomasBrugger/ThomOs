#include "stack.h"
#include "assert.h"
#include "stdlib.h"
#include "string.h"

typedef struct Stack
{
    Stack_Config* pConfig;
    uint8_t* buffer;
    size_t topElementIndex;
} Stack;

Stack_Handle Stack_create(Stack_Config* pConfig)
{
    assert(NULL != pConfig);
    assert((0 != pConfig->dataSize) && (0 != pConfig->elementCount));

    Stack_Handle handle = (Stack_Handle)malloc(sizeof(Stack));

    if(NULL != handle)
    {
        if(NULL != pConfig->initBuffer)
        {
            handle->buffer = pConfig->initBuffer;
        }
        else
        {
            size_t bufferSize = pConfig->elementCount * pConfig->dataSize;
            handle->buffer = (uint8_t*)malloc(bufferSize);
        }

        handle->topElementIndex = 0;

        if(NULL == handle->buffer)
        {
            free(handle);
        }
    }

    return handle;
}

Result_t Stack_destroy(Stack_Handle handle)
{
    free(handle->buffer);
    free(handle);

    return RESULT_SUCCESS;
}

Result_t Stack_push(Stack_Handle handle, Generic_Handle data, size_t size)
{
    assert(NULL != handle && NULL != data);
    assert(size == handle->pConfig->dataSize);

    uint8_t* dest = &(handle->buffer[handle->topElementIndex]);
    memcpy(dest, data, size);
    handle->topElementIndex++;

    return RESULT_SUCCESS;
}

Result_t Stack_pop(Stack_Handle handle, Generic_Handle data, size_t size)
{
    assert(NULL != handle && NULL != data);
    assert(size == handle->pConfig->dataSize);

    uint8_t* src = &(handle->buffer[handle->topElementIndex]);
    memcpy(data, src, size);
    handle->topElementIndex++;

    return RESULT_SUCCESS;

}

Result_t Stack_reset(Stack_Handle handle)
{
    assert(NULL != handle);

    handle->topElementIndex = 0;

    return RESULT_SUCCESS;
}