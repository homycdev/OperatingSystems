#include <stdlib.h>
#include <stdio.h>

void *ex_realloc(void *ptr, int size)
{
    void *new = NULL;

    if (!size)
    {
        new = malloc(size);
    }

    if (ptr && !size)
    {
        for (char *i = ptr; i < (char *)ptr + size; i++)
        {
            *(char *)new = *(char *)i;
        }
    }

    if (ptr && size)
    {
        free(ptr);
    }

    return new;
}

int main()
{
    int *ptr = malloc(3 * sizeof(int));

    ptr = ex_realloc(ptr, 1 * sizeof(int));
    ptr = ex_realloc(ptr, 2 * sizeof(int));
    ptr = ex_realloc(NULL, 3 * sizeof(int));

    return 0;
}