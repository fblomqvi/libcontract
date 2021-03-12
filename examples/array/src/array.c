#include "array.h"

#include <contract/contract.h>
#include <stdint.h>

struct array *array_alloc(size_t size)
{
    // Alloc memory for the struct and the data.
    uint8_t *buffer = malloc(sizeof(struct array) + size * sizeof(int));
    if (!buffer)
        return NULL;

    struct array *arr = (struct array *) buffer;
    arr->data = (int *) (buffer + sizeof(struct array));
    arr->size = size;
    return arr;
}

void array_free(struct array *arr)
{
    free(arr);
}

void array_fill(struct array *arr, int value)
{
    EXPECT(arr);
    for (size_t i = 0; i < arr->size; i++) {
        arr->data[i] = value;
    }
}
