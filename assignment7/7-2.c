#include <stdio.h>
#define N 4

typedef float array_f[N];

void inner2(float *u, float *v, int length, float *dest) {
    int i;
    float sum0 = 0.0f;
    float sum1 = 0.0f;
    float sum2 = 0.0f;
    float sum3 = 0.0f;
    float sum4 = 0.0f;
    for (i = 0; i < length; i+=4){
        sum1 += u[i] * v[i];
        sum2 += u[i+1] * v[i+1];
        sum3 += u[i+2] * v[i+2];
        sum4 += u[i+3] * v[i+3];
    }
    sum0 += sum1 + sum2 + sum3 + sum4;
    *dest = sum0; 
    }

int main(int argc, char *argv[]){
    array_f u = {1, 2, 3, 4};
    array_f v = {5, 6, 7, 8};
    float result;
    inner2(u, v, N, &result);
}
