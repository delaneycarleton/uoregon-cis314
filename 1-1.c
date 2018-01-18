
#include <stdio.h>
void printBytes(unsigned char *start, int len) {
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
}
    printf("\n");
}
void printInt(int x) {
    printBytes((unsigned char *) &x, sizeof(int));
}
void printFloat(float x) {
    printBytes((unsigned char *) &x, sizeof(float));
}
void printShort(short x) {
	
    printBytes((unsigned char *) &x, sizeof(short));
}
void printLong(long x) {
    printBytes((unsigned char *) &x, sizeof(long));
}
void printDouble(double x) {
    printBytes((unsigned char *) &x, sizeof(double));
}
int main(int argc, char *argv[])
{
    int i = 1;
    float f = 5;
    short j = 9;
    long m = 15;
    double n = 10;
    
    printInt(i);
    printFloat(f);
    printShort(j);
    printLong(m);
    printDouble(n);


    printf("Here are some tests: \n\n");
    
    printInt(0);
    printInt(9);
    printInt(23);
    printInt(128);
    return 0;
}
