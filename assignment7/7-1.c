#include <stdio.h>
#define N 4
typedef int array_t[N][N];

void f(array_t a, int x, int y) {
    int z = x * y;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j){
            a[i][j] = i * z + j;
        }
    }
}

int main(int argc, char *argv[]) {
    //int a[N][N];
    array_t a;
    int x = 5;
    int y = 10;
    f(a,x,y);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j){
            printf("%d ", a[i][j]);
    
        }
        printf("\n");
    }
    
        printf("\n");
}
