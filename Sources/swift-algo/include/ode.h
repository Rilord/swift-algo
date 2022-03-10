#ifndef ALGO_ODE_H
#define ALGO_ODE_H

#include "common.h"

ALGO_EXPORT arr *algo_euler(float x0, float y0, float h,  int n,
                            float (*equation)(float, float));

ALGO_EXPORT arr *algo_runge_kutta(float x0, float y0, float a, float h, int n,
                                  float (*equation)(float, float));


ALGO_EXPORT mat *algo_picard(float x0, float h, const int n);

#endif //UNTITLED_ODE_H

