#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    // SETUP
    // first, read the minuend (number to be subtracted from)
    bool minuend[8]; // suggested that you store bits as array of bools; minuend[0] is the LSB
    fread(minuend,sizeof(minuend),1,fp); // read 8 bytes into minuend

    // reverse the number
    unsigned int k = 0;
    unsigned int m = 7;
    bool temp1;
    while(k<m){ // read MSB first as that is what comes first in the file
        temp1 = minuend[k];
        minuend[k] = minuend[m];
        minuend[m] = temp1;
        k++;
        m--;
    }
    
    // reading the newline
    char newLine;
    fscanf(fp, "%c", &newLine);
    
    // //second, read the subtrahend (number to subtract)
    bool subtrahend[8]; // suggested that you store bits as array of bools; subtrahend[0] is the LSB
    fread(subtrahend,sizeof(subtrahend),1,fp); // read 8 bytes into subtrahend
   
    // reverse the number
    unsigned int i = 0;
    unsigned int j = 7;
    bool temp2;
    while(i<j){ // read MSB first as that is what comes first in the file
        temp2 = subtrahend[i];
        subtrahend[i] = subtrahend[j];
        subtrahend[j] = temp2;
        i++;
        j--;
    }


    // WE WILL DO SUBTRACTION BY NEGATING THE SUBTRAHEND AND ADD THAT TO THE MINUEND
    // Negate the subtrahend
    // flip all bits
    char tmp;
    for( int bit=0; bit<8; bit++ ){
        tmp = subtrahend[bit];
        //printf("%c\n", tmp);
        if(tmp=='1'){
            subtrahend[bit] = false;
        } else{
            subtrahend[bit] = true;
        }
    }

    // add one
    bool carry = true; // to implement the 'add one' logic, we do binary addition logic with carry set to true at the beginning
    char holder;
    for (int i=0; i<8; i++) { // iterate from LSB to MSB
        holder = subtrahend[i];
        if(holder==0 && i==0){
            carry = false;
            subtrahend[i] = true;
        } else if(holder==1 && i==0){
            carry = true;
            subtrahend[i] = false;
        } else if(holder==0 && carry==true && i>0){
            carry = false;
            subtrahend[i] = true;
        } else if(holder==0 && carry==false && i>0){
            carry = false;
            subtrahend[i] = false;
        } else if(holder==1 && carry==true && i>0){
            carry = true;
            subtrahend[i] = false;
        } else if(holder==1 && carry==false && i>0){
            carry = false;
            subtrahend[i] = true;
        }
    }

    // Add the minuend and the negated subtrahend
    bool difference[8];
    char tmpMinud;
    char tmpSubtr;
    int index = 7;
    bool carryTwo = false;
    for (int i=0; i<8; i++) { // iterate from LSB to MSB
        tmpMinud = minuend[i];
        tmpSubtr = subtrahend[i];
        if((tmpMinud=='0') && (tmpSubtr==0) && (i==0)){
            carryTwo = false;
            difference[index] = false;
            index--;
        } else if((tmpMinud=='1') && (tmpSubtr==1) && (i==0)){
            carryTwo = true;
            difference[index] = false;
            index--;
        } else if((((tmpMinud=='0') && (tmpSubtr==1)) || ((tmpMinud=='1') && (tmpSubtr==0)))  && (i==0)){
            carryTwo = false;
            difference[index] = true;
            index--;
        }else if((tmpMinud=='0') && (tmpSubtr==0) && (carryTwo==true) && (i>0)){
            carryTwo = false;
            difference[index] = true;
            index--;
        } else if((tmpMinud=='0') && (tmpSubtr==0) && (carryTwo==false) && (i>0)){
            carryTwo = false;
            difference[index] = false;
            index--;
        } else if((tmpMinud=='1') && (tmpSubtr==1) && (carryTwo==true) && (i>0)){
            carryTwo = true;
            difference[index] = true;
            index--;
        }  else if((tmpMinud=='1') && (tmpSubtr==1) && (carryTwo==false) && (i>0)){
            carryTwo = true;
            difference[index] = false;
            index--;
        } else if((((tmpMinud=='1') && (tmpSubtr==0)) || ((tmpMinud=='0') && (tmpSubtr==1))) && (carryTwo==true) && (i>0)){
            carryTwo = true;
            difference[index] = false;
            index--;
        } else if((((tmpMinud=='1') && (tmpSubtr==0)) || ((tmpMinud=='0') && (tmpSubtr==1))) && (carryTwo==false) && (i>0)){
            carryTwo = false;
            difference[index] = true;
            index--;
        }
    }

    //print the difference bit string
    for (int i=0; i<8; i++){
        printf("%d",difference[i]);
    }
    return EXIT_SUCCESS;

}
