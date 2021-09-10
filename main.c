#include <stdio.h>
#include "bigInt.h"

int main() {

    char num1[100], num2[100];

    scanf("%s %s", num1, num2);

    printf("Add: %s\n", add(num1, num2));
    printf("Subtract: %s\n", subtract(num1, num2));
    printf("Multiply: %s\n", multiply(num1, num2));
    printf("Divide: %s\n", divide(num1, num2));
    printf("Compare: %d\n", compare(num1, num2));
    printf("Modulus %s\n", modulus(num1, num2));
    
    //printf("Power: %s\n", power(num1, num2));
    //printf("Factorial of 1st: %s\n", factorial(num1));
    //printf("Factorial of 2nd: %s\n", factorial(num2));

    return 0;
}

