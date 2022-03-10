//
//  File.c
//  
//
//  Created by Kirill Diordiev on 10.03.2022.
//

#include "common.h"

ALGO_EXPORT void create_matrix(const int m, const int n, mat **a) {
    *a = (mat *) malloc(sizeof(mat));
    (*a)->rows = m;
    (*a)->cols = n;
    (*a)->data = (float **) malloc(sizeof(float *) * m);

    for (int i = 0; i < m; i++) {
        (*a)->data[i] = (float *) (calloc(n, sizeof(float)));
    }
}

ALGO_EXPORT void free_matrix(mat *a) {
    for (int i = 0; i < a->rows; ++i) {
        free(a->data[i]);
    }
    free(a->data);
    free(a);
}

ALGO_EXPORT void create_array(const int n, arr **a) {
    *a = (arr *) malloc(sizeof(arr));
    (*a)->size = n;
    (*a)->data = (float *) calloc(n, sizeof(float));
}

ALGO_EXPORT void free_array(arr *a) {
    free(a->data);
    free(a);
}


