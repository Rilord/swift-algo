//
//  File.c
//  
//
//  Created by Kirill Diordiev on 10.03.2022.
//

#include "ode.h"

float fapprox(float x) {
    return
            x * x * x / 3.f;
}

float sapprox(float x) {
    return
            fapprox(x) +
            powf(x, 7.f) / 63.f;
}

float tapprox(float x) {
    return
            1.f * sapprox(x) +
            2.f * powf(x, 11.f) / 2079.f +
            1.f * powf(x, 15.f) / 59535.f;
}

float foapprox(float x) {
    return
            1.f * sapprox(x) +
            2.f * powf(x, 11.f) / 2079.f +
            13.f * powf(x, 15.f) / 218295.f +
            82.f * powf(x, 19.f) / 37328445.f +
            662.f * powf(x, 23.f) / 10438212015.f +
            4.f * powf(x, 27.f) / 3341878155.f +
            1.f * powf(x, 31.f) / 109876902975.f;
}

ALGO_EXPORT arr *algo_euler(float x0, float y0, float h,  int n,
        float (*equation)(float, float)) {

    arr *result;

    create_array(n + 1, &result);

    for (int i = 0; i <= n; ++i) {
        result->data[i] = y0;
        y0 += h * (*equation)(x0, y0);
        x0 += h;
    }

    return result;

}

ALGO_EXPORT arr *algo_runge_kutta(float x0, float y0, float a, float h, int n,
                                  float (*equation)(float, float)) {

    arr *result;
    create_array(n + 1, &result);

    for (int i = 0; i <= n; ++i) {
        result->data[i] = y0;
        y0 +=
        h * ((1 - a) * (*equation)(x0, y0) +
        a * (*equation)(x0 + (h / 2.f / a), y0 +
        h * (*equation)(x0, y0) / 2 / a));
        
        x0 += h;
    }

    return result;
}

ALGO_EXPORT mat *algo_picard(float x0, float h, const int n) {
    mat *result;
    create_matrix(4, n + 1, &result);

    for (int i = 0; i <= n; ++i) {
        result->data[0][i] = fapprox(x0);
        result->data[1][i] = sapprox(x0);
        result->data[2][i] = tapprox(x0);
        result->data[3][i] = foapprox(x0);

        x0 += h;
    }

    return result;
}
