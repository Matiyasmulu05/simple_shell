#include <stdlib.h>

/**
 * bfree - Frees a pointer and sets it to NULL
 * @ptr: Pointer to be freed
 * 
 * Return: Always 0 (for consistency with other functions)
 */
int bfree(void **ptr)
{
    if (ptr != NULL && *ptr != NULL)
    {
        free(*ptr);
        *ptr = NULL;
    }
    return 0;
}
