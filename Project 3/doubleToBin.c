#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EXP_SZ 11
#define FRAC_SZ 52

int main(int argc, char *argv[]) {

    // SETUP

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return 0;
    }

    // first, read the number
    double value;
    fscanf(fp, "%lf", &value);


    //THE SIGN BIT
    if(value<0){
        printf("%d_",1);
    } else if(value>=0){
        printf("%d_",0);
    }
    

    // THE EXPONENT
    int nmb = (int) value;
    int count = 0;
    int exponent = 0;
    if(value==0){
        for ( int bit=10; 0<=bit; bit-- ) {
        size_t bit_val = ((1<<1)-1) & exponent>>bit*1; // shift and mask
        char character = bit_val ? '1' : '0';
        printf("%c",character);
    }
    printf("_");

    //THE FRAC
    int frac = 0;
    for ( int bit=51; 0<=bit; bit-- ) {
        size_t bit_val = ((1<<1)-1) & frac>>bit*1; // shift and mask
        char character = bit_val ? '1' : '0';
        printf("%c",character);
    }
        // THE EXPONENT
        } else if(value>0){
            while(nmb>0){
            nmb = nmb/2;
            count++;
        }
        if(abs(value)==2.0){
            exponent = 1024;
        } else{
            exponent = 1023 + (count-1);
        }
        

        for ( int bit=10; 0<=bit; bit-- ) {
            size_t bit_val = ((1<<1)-1) & exponent>>bit*1; // shift and mask
            char character = bit_val ? '1' : '0';
            printf("%c",character);
        }
        printf("_");

        // THE FRAC
        int frac = 0;
        for ( int bit=51; 0<=bit; bit-- ) {
            size_t bit_val = ((1<<1)-1) & frac>>bit*1; // shift and mask
            char character = bit_val ? '1' : '0';
            printf("%c",character);
        }   
    }
}
