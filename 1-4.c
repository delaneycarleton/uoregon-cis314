#include <stdio.h>
int even (unsigned int x) {
    unsigned  int mask = 0x55555555;
    unsigned int x2 = mask & x;
    return (x2 != 0); 
}

int main(int argc, char *argv[]){
    printf("%d\n", even(0x0));
    printf("%d\n", even(0x1));
    printf("%d\n", even(0x2));
    printf("%d\n", even(0x3));
    printf("%d\n", even(0xFFFFFFFF));
    printf("%d\n", even(0xAAAAAAAA));
    return 0;
}
    
/* I  created an unsigned int mask which is set to the hexadecimal where 1 is at every even intex. I then created an unsigned int x2 set equal to mask and x. Since the return statement is 0 or 1, I returned x2 not equal to 0. */
