/***********************************************
    This project has aim to show
    memory organization of C struct,
    with and without padding.
***********************************************/
#include <stdio.h>

/******************************
    It has "Padding" effect
    in memory to 4 bytes,
    It will be showed by using
    sizeof() and by viewing memory
******************************/
typedef struct Alpha {
    unsigned char byte;
    unsigned int value;
} Alpha;

/******************************
    Beta use:
    __attribute__((packed)).
    
    It has effect "No padding"
    in memory to 4 bytes,
    it has difference with
    Alpha struct.
******************************/
typedef struct Beta {
    unsigned char byte;
    unsigned int value;
} __attribute__((packed)) Beta;

Alpha a;
Beta b;

int main() {
    a.byte  = 0xaa;
    a.value = 0x11223344;
    
    b.byte  = 0xbb;
    b.value = 0x11223344;
    
    /*Difference in size!*/
    printf("sizeof(Alpha) = %lu\n", sizeof(Alpha));
    printf("sizeof(Beta) = %lu\n", sizeof(Beta));  
    
    /*Difference in actual memory*/
    int i;
    for(i = 0; i < sizeof(Alpha); i++) {
        printf("%#2x ", ((unsigned char*)&a)[i]);
    }
    printf("\n");
    for(i = 0; i < sizeof(Beta); i++) {
        printf("%#2x ", ((unsigned char*)&b)[i]);
    }
    printf("\n");
    
    return 0;
}
