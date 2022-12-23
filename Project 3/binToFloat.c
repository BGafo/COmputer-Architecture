#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define EXP_SZ 8
#define FRAC_SZ 23

int main(int argc, char *argv[]) {

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    // SETUP

    bool input[32]; 
    fread(input,sizeof(input),1,fp); 
    float number = 0.0;
    int exponent = 0;
    float finalExp = 0;
    int e = 0;
    int j = 7;
    int k = 1;
    float frac = 0;
    float finalFrac;
    bool sign = false;
    for(int i = 0; i<31; i++){
        if((input[0] & 1)==true){
            sign = true;
        }
        if((i>=1) && (i<=8) && ((input[i] & 1)==false)){
            j--;
        }else if((i>=1) && (i<=8) && ((input[i] & 1)==true)){
            exponent = exponent + pow(2, j);
            j--;
        }
        if((i>8) && ((input[i] & 1)==false)){
            k++;
        }else if((i>8) && ((input[i] & 1)==true)){
            frac = frac + pow(0.5, k);
            k++;
        }
    }
    e = exponent - 127;
    finalExp = pow(2, e);
    finalFrac = (float) (1.0 + frac);
    if(sign==true){
        number = -1 * finalFrac * finalExp;
    } else{
        number = finalFrac * finalExp;
    }
        printf("%f\n", number);
    return EXIT_SUCCESS;

}
