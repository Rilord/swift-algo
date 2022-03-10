#ifndef ODE_TYPES_STRUCT_H
#define ODE_TYPES_STRUCT_H

#include "types.h"

typedef struct {
    size_t size;
    float *data;
} arr;

typedef struct {
    size_t rows;
    size_t cols;
    float **data;
} mat;

#endif //ODE_TYPES_STRUCT_H

