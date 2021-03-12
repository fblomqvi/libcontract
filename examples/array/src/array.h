#ifndef __ARRAY_ARRAY_H
#define __ARRAY_ARRAY_H

#include "contract/contract.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

struct array {
    int *data;
    size_t size;
};

struct array *array_alloc(size_t size);

void array_free(struct array *arr);

void array_fill(struct array *arr, int value);

static inline int array_get(struct array *arr, size_t idx)
{
    EXPECT(arr && idx < arr->size);
    return arr->data[idx];
}

static inline void array_set(struct array *arr, size_t idx, int value)
{
    EXPECT(arr && idx < arr->size);
    arr->data[idx] = value;
}

static inline size_t array_size(struct array *arr)
{
    EXPECT(arr);
    return arr->size;
}

#ifdef __cplusplus
}
#endif

#endif /* __ARRAY_ARRAY_H */
