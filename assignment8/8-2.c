#include <stdio.h>
#include <stdlib.h>

struct block {
    
    unsigned char valid;
    unsigned int tag;       //26-bit tag
    unsigned char value[4];     //4-byte value
};

unsigned int getOffset(unsigned int address){
    return (address<<30)>>30;   //shift left 30 and then shift this right 30 to get offset

}

unsigned int getSet(unsigned int address){
    return (address<<26)>>28;   //shift left 26 and shift right 28 to get set
}

unsigned int getTag(unsigned int address){
    return (address>>6);        //shift right 6 to get tag
}

int main(int argc, char* argv[]) {

    struct block cache[16];         //16 cache sets
    for (int i = 0; i < 16; i++){
        cache[i].valid = 0;         //sets blocks to invalid
    }
    
    char input[256];                //place limit on user input
    unsigned int input_address, input_value;        
    
    int done = 0;
    while(!done){
        printf("Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: "); //prompt user to input
        scanf("%s", input);     //get user input
        printf("\n");           //print blank line inbetween so it looks cleaner 

        unsigned int set, tag;
        struct block b;

        switch(input[0]){       //use a switch with 4 cases
            case 'r':           //read a byte
                printf("Enter 32-bit unsigned hex address: ");  //prompt user
                scanf("%x", &input_address);        //get user input
                printf("\n");
                set = getSet(input_address);        //set corresponding to address
                tag = getTag(input_address);        //tag corresponding to address

                printf("looking for set: %d - tag: %d\n", set, tag);
                printf("\n");
                b = cache[set];
                int offset = input_address % 4; //set offset equal to address modulo 4
                if(b.valid == 1){           //if valid
                    printf("found set: %d - tag: %d -offset: %d - valid: %d -value: %x\n", set, b.tag, offset, b.valid, b.value[offset]); 
                    printf("\n");
                    
                    if (b.tag == tag){      // if cache[set] tag is equal to tag
                        printf("hit!\n");
                        printf("\n");
                    }
                    else{
                        printf("tags don't match - miss!\n"); //cache[se]t tag not equal to tag
                        printf("\n");
                    }
                }
                else{
                    printf("not valid set found - miss!\n");    //value doesn't correspond to address
                    printf("\n");
                }
                
                
                break;

            case 'w':
                printf("Enter 32-bit unsigned hex address: "); //prompt user
                scanf("%x", &input_address);                //get user input
                printf("\n");
            

                printf("Enter 32-bit unsigned hex value: ");
                scanf("%x", &input_value);
                printf("\n");
                
                set = getSet(input_address);
                tag = getTag(input_address);
                b = cache[set];
                if (cache[set].valid == 1){         //use cache[set] instead of b so b is not changed
                    printf("evicting block - set: %d - tag: %d - valid: %d - value: %x %x %x %x\n", set, b.tag, b.valid, b.value[0], b.value[1], b.value[2], b.value[3]);
                    printf("\n");
                }
                cache[set].tag = tag;
                cache[set].valid = 1;
                //address is a multiple of 4
                cache[set].value[3] = input_value>>24;  //right shift 24
                cache[set].value[2] = (input_value<<8)>>24; //left shift 8 then right shift 24
                cache[set].value[1] = (input_value<<16)>>24;    //left shift 16 then right shift 24
                cache[set].value[0] = (input_value<<24)>>24;    //left shift 24 then right shift 24
                b = cache[set];

                //write simulates moving an entire block from memory into the cache
            
                printf("wrote set: %d - tag: %d - valid: %d - value: %x %x %x %x\n", set, b.tag, b.valid, b.value[0], b.value[1], b.value[2], b.value[3]); 
                printf("\n");
                 
                break;

            case 'p':
                for(int i =0; i<16;i++){
                    b = cache[i];
                    if(b.valid == 1){

                        printf("set: %d - tag: %d - valid: %d - value: %x %x %x %x\n", i, b.tag, b.valid, b.value[0], b.value[1], b.value[2], b.value[3]);
                        printf("\n");
                    }
                }
                //p prints the values
                break;

            case 'q':
                done = 1; //quit the simulation
                break;
        }

        
    }
    
    return 0;
}

