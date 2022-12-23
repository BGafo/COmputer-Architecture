#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Struct to hold the open and close braces and the pointer to the next element.
struct element {
    // char open; // not needed
    char close;
    struct element* next;
};

void push ( struct element** root, char close) {
    struct element* newElement = malloc ( sizeof ( struct element));
    newElement->close = close;
    newElement->next = *root;
    *root = newElement;
    return;
}

char pop (struct element** root) {
    char close;
    if ( (*root) != NULL){
    struct element* temp = *root;
    close = temp->close;
    *root = temp->next;
    free(temp);
    }
    return close;
}

int main(int argc, char* argv[]) {

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    struct element* root = NULL;
    bool balanced = true;

    char buff;
    while ( fscanf(fp, "%c", &buff)==1 ) {
        if(((buff=='>') || (buff==')') || (buff==']') || (buff=='}')) && (root==NULL)){
            balanced = false;
            break;
        }
        switch(buff) {
            case '<' : 
            case '(' :
            case '[' :
            case '{' :
                push( &root, buff);
                break;  
            case '>' :
            case ')' :
            case ']' :
            case '}' :
                if((root) == NULL){
                    balanced = false;
                    break;
                } else {
                    char temp = pop(&root);
                    if (temp == '(' && (buff != ')')){
                        balanced = false;
                        break;
                    } 
                     else if (temp == '<' && (buff != '>')){
                        balanced = false;
                        break;
                    }
                     else if (temp == '[' && (buff != ']')){
                        balanced = false;
                        break;
                    }
                     else if (temp == '{' && (buff != '}')){
                        balanced = false;
                        break;
                     }
                    else {
                        balanced = true;
                        break;
                    }
                }
            default :
                printf("Invalid character\n" );
                   
        }
    }

    if((root) != NULL){
        balanced = false;
    }
    printf ( balanced ? "yes" : "no" );
    
    fclose(fp);
    return 0;
}
