#include <stdio.h>
#include <stdlib.h>

void polynomialLongDivision(int dividend[], int divisor[], int quotient[], int remainder[], int dividendSize, int divisorSize) {
    int tempDividend[dividendSize];
    int tempDividendSize = dividendSize;

    for (int i = 0; i < dividendSize; i++) {
        tempDividend[i] = dividend[i];
    }

    for (int i = 0; i <= dividendSize - divisorSize; i++) {
        int quotientTerm = tempDividend[i] / divisor[0];
        quotient[i] = quotientTerm;

        for (int j = 0; j < divisorSize; j++) {
            tempDividend[i + j] = tempDividend[i + j] - (quotientTerm * divisor[j]);
        }
    }

    for (int i = 0; i < divisorSize - 1; i++) {
        remainder[i] = tempDividend[dividendSize - divisorSize + 1 + i];
    }
}

int main() {
    int dividend[] = {1, -3, 2, 1};  
    int dividendSize = sizeof(dividend) / sizeof(dividend[0]);
    int divisor[] = {1, -2};  
    int divisorSize = sizeof(divisor) / sizeof(divisor[0]);
    int quotient[dividendSize - divisorSize + 1];  
    int remainder[divisorSize - 1];  

    polynomialLongDivision(dividend, divisor, quotient, remainder, dividendSize, divisorSize);

    printf("Quotient: ");
    for (int i = 0; i < dividendSize - divisorSize + 1; i++) {
        printf("%dx^%d ", quotient[i], dividendSize - divisorSize - i);
    }

    printf("\nRemainder: ");
    for (int i = 0; i < divisorSize - 1; i++) {
        printf("%dx^%d ", remainder[i], divisorSize - 2 - i);
    }

    printf("\n");

    return 0;
}