#include <stdio.h>
void printBytes(unsigned char *start, int len) {
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}
unsigned int combine (unsigned int x, unsigned int y){
    unsigned int x2 = x & (~0xFFFFFF);
    unsigned int y2 = y & (0xFFFFFF);
    return ( x2 | y2);
}

int main(int argc, char *argv[]){
    unsigned int x = 0x12345678;
    unsigned int y = 0xABCDEF00;
    printf("Printing x:\n");
    printBytes((unsigned char *)&x, sizeof(unsigned int));
    printf("Printing y:\n");
    printBytes((unsigned char *)&y, sizeof(unsigned int));
    printf("Printing combined:\n");
    unsigned int c = combine(x,y); 
    printBytes((unsigned char *)&c, sizeof(unsigned int));
    return 0;
}
