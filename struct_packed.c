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
    printf("sizeof(Beta)  = %lu\n", sizeof(Beta));  
    printf("\n");
    
    /*Difference in actual memory, bytes and its address*/
    int i;
    printf("Alpha bytes and its addresses:\n");
    for(i = 0; i < sizeof(Alpha); i++) {
        printf("%#2x\t%p\n", ((unsigned char*)&a)[i], &(((unsigned char*)&a)[i]));
    }
    printf("\n");
    printf("Beta  bytes and its addresses:\n");
    for(i = 0; i < sizeof(Beta); i++) {
        printf("%#2x\t%p\n", ((unsigned char*)&b)[i], &(((unsigned char*)&b)[i]));
    }
    printf("\n");
    
    /*Addresses of fields:*/
    printf("Alpha a.byte:  %p\n", &a.byte);
    printf("Alpha a.value: %p\n", &a.value);
    printf("\n");
    printf("Beta  b.byte:  %p\n", &b.byte);
    printf("Beta  b.value: %p\n", &b.value);
    
    return 0;
}
