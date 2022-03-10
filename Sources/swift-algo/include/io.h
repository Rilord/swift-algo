//
//  Header.h
//  
//
//  Created by Kirill Diordiev on 10.03.2022.
//

#ifndef ODE_IO_H
#define ODE_IO_H

#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef ALGO_PRINT_PRECISION
#  define ALGO_PRINT_PRECISION    5
#endif

#ifndef ALGO_PRINT_MAX_TO_SHORT
#  define ALGO_PRINT_MAX_TO_SHORT 1e5
#endif


#ifndef ALGO_PRINT_PRECISION
#define ALGO_PRINT_PRECISION 5
#endif

#ifndef ALGO_PRINT_COLOR
#define ALGO_PRINT_COLOR "\033[36m"
#endif

#ifndef ALGO_PRINT_COLOR_RESET
#define ALGO_PRINT_COLOR_RESET "\033[0m"
#endif

ALGO_INLINE void algo_mat4_print(mat4 matrix, FILE * __restrict ostream) {
    char buff[16];
    int i, j, cw[4], cwi;

#define m 4
#define n 4

    fprintf(ostream, "Matrix (float%dx%d): " ALGO_PRINT_COLOR "\n", m, n);

    cw[0] = cw[1] = cw[2] = cw[3] = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] < ALGO_PRINT_MAX_TO_SHORT)
                cwi = sprintf(buff, "% .*f", ALGO_PRINT_PRECISION, matrix[i][j]);
            else
                cwi = sprintf(buff, "% g", matrix[i][j]);
            cw[i] = ALGO_MAX(cw[i], cwi);
        }
    }

    for (i = 0; i < m; i++) {
        fprintf(ostream, " |");

        for (j = 0; j < n; j++)
            if (matrix[i][j] < ALGO_PRINT_MAX_TO_SHORT)
                fprintf(ostream, "% *.*f", cw[j], ALGO_PRINT_PRECISION, matrix[i][j]);
            else
                fprintf(ostream, "% *g", cw[j], matrix[i][j]);

        fprintf(ostream, " |\n");
    }

    fprintf(ostream, ALGO_PRINT_COLOR_RESET "\n");

#undef m
#undef n
}

ALGO_INLINE void algo_mat_print(mat matrix, FILE * __restrict ostream) {

    char buff[16];
    int m = matrix.rows, n = matrix.cols;
    int i, j, cwi;


    fprintf(ostream, "Matrix (float%dx%d): " ALGO_PRINT_COLOR "\n", m, n);


    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix.data[i][j] < ALGO_PRINT_MAX_TO_SHORT)
                cwi = sprintf(buff, "% .*f", ALGO_PRINT_PRECISION, matrix.data[i][j]);
            //else
            //    cwi = sprintf(buff, "% g", matrix.data[i][j]);
            //cw[i] = ALGO_MAX(cw[i], cwi);
        }
    }

    for (i = 0; i < m; i++) {
        fprintf(ostream, " |");

        for (j = 0; j < n; j++)
            if (matrix.data[i][j] < ALGO_PRINT_MAX_TO_SHORT)
                fprintf(ostream, "% *.*f", 1, ALGO_PRINT_PRECISION, matrix.data[i][j]);
            //else
            //    fprintf(ostream, "% *g", cw[j], matrix.data[i][j]);

        fprintf(ostream, " |\n");
    }

    fprintf(ostream, ALGO_PRINT_COLOR_RESET "\n");

}

ALGO_INLINE void algo_array_print(arr array, FILE * __restrict ostream) {
    int i, m = array.size;

    fprintf(ostream, "Vector (float%d): " ALGO_PRINT_COLOR "\n (", m);

    for (i = 0; i < m; i++) {
        if (array.data[i] < ALGO_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " % .*f", ALGO_PRINT_PRECISION, array.data[i]);
        else
            fprintf(ostream, " % g", array.data[i]);
    }

    fprintf(ostream, " )" ALGO_PRINT_COLOR_RESET "\n\n");
}

#endif //ODE_IO_H

