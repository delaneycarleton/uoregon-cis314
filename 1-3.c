# include <stdio.h>
unsigned int replace(unsigned int x, int i, unsigned char b)

{   
    unsigned int x2;
    switch(i) {
    case 0:
       x2 = x&0xFFFFFF00;
       break;
    case 1:
        x2 = x&0xFFFF00FF;
        break;
    case 2:
        x2 = x&0xFF00FFFF;
        break;
    case 3:
        x2 = x&0x00FFFFFF;
        break;
    }
    return (x2 | (b<<(8*i))); 
}
int main(int argc, char *argv[]){
    printf("%X\n",replace(0x12345678, 0, 0xAB));
    printf("%X\n", replace(0x12345678, 2, 0xAB)); 
    return 0;
}
