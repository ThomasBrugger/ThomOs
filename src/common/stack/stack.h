/*
    Opaque implementation of a stack data structure.
*/

#include "types.h"

typedef struct Stack* Stack_Handle;

typedef struct Stack_Config
{
    Generic_Handle initBuffer;
    size_t elementCount;
    size_t dataSize;
} Stack_Config;

/*
    Creates and returns a stack instance with input config.
*/
Stack_Handle Stack_create(Stack_Config* pConfig);

/*
    Pushs input data to stack.
*/
Result_t Stack_push(Stack_Handle handle, Generic_Handle data, size_t size);

/*
    Pops top level element from stack and returns it.
*/
Result_t Stack_pop(Stack_Handle handle, Generic_Handle data, size_t size);

/*
    Sets the stack to init state
*/
Result_t Stack_reset();