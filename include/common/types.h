/*
    Defintion of types used by the OS.
*/

#include <stdint.h>
#include <stddef.h>

/* 
    Result return type - used whenever possible
*/
typedef enum
{
    RESULT_SUCCESS,
    RESULT_FAILED,
    RESULT_NOT_IMPLEMENTED
} Result_t;

typedef void* Generic_Handle;