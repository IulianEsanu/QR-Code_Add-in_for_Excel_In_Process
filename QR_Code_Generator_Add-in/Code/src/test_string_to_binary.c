#include <stdio.h>
#include <string.h>

void stringToBinary(const char* str) {
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        char c = str[i];
        
        for (int j = 7; j >= 0; j--) {
            int bit = (c >> j) & 1;
            printf("%d", bit);
        }
        
        printf(" ");
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); //fgets it's like scanf but it doesen't stop if there is a space and avoid buffer overloading
    str[strcspn(str, "\n")] = '\0'; 
    
    printf("Binary representation: ");
    stringToBinary(str);
    
    return 0;
}