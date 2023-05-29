#include <stdio.h>
#include <stdlib.h>

// Function to perform long division with polynomials
void polynomialLongDivision(int dividend[], int divisor[], int quotient[], int remainder[], int dividendSize, int divisorSize) {
    int tempDividend[dividendSize];
    int tempDividendSize = dividendSize;

    // Copy the dividend into a temporary array
    for (int i = 0; i < dividendSize; i++) {
        tempDividend[i] = dividend[i];
    }

    // Perform long division
    for (int i = 0; i <= dividendSize - divisorSize; i++) {
        // Compute the quotient term
        int quotientTerm = tempDividend[i] / divisor[0];

        // Store the quotient term
        quotient[i] = quotientTerm;

        // Update the dividend with the remainder
        for (int j = 0; j < divisorSize; j++) {
            tempDividend[i + j] = tempDividend[i + j] - (quotientTerm * divisor[j]);
        }
    }

    // Copy the remainder into the remainder array
    for (int i = 0; i < divisorSize - 1; i++) {
        remainder[i] = tempDividend[dividendSize - divisorSize + 1 + i];
    }
}

int main() {
    int dividend[] = {1, -3, 2, 1};  // Coefficients of dividend polynomial: x^3 - 3x^2 + 2x + 1
    int dividendSize = sizeof(dividend) / sizeof(dividend[0]);

    int divisor[] = {1, -2};  // Coefficients of divisor polynomial: x - 2
    int divisorSize = sizeof(divisor) / sizeof(divisor[0]);

    int quotient[dividendSize - divisorSize + 1];  // Quotient array
    int remainder[divisorSize - 1];  // Remainder array

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