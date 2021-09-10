#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <stdio.h>

char* add(char* num1, char* num2);

// computeSubtract only works with the positive numbers so the driver code for it is in subtract function
char* computeSubtract(char *larger, char *smaller);
char* subtract(char* num1, char *num2);

char* multiply(char *num1, char *num2);

char* factorial(char* num);

int compare(char* num1, char *num2);

char* power(char* num1, char* num2);

char* divide(char* num1, char* num2);

char* modulus(char* num1, char* num2);

#endif
