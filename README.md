# BigInt
C library for operating with signed integers of arbitrary size.

## Introduction
BigInteger library is used for mathematical operations which involves very big integer calculations that are outside the limit of all available primitive data types.  
For example factorial of 100 contains 158 digits in it so we can’t store it in any primitive data type available but we can use a data structure to store each digit of that number and then operate on that.   

It supports various basic mathematical operations such as :

1. Addition
2. Subtraction
3. Multiplication
4. Divison
5. Modulus
6. Factorial
7. Power
8. Comparison 

and have some utility functions.


## Design and Specifications 

All the function of library takes a string as an input then internally converts it into a linkedlist with each node containing each digit of that number.

Input String : "12345"  
LinkedList : 1 -> 2 -> 3 -> 4 -> 5 -> NULL

After operating on the linkedlist, a new string with output number is created and returned.

*****

1. #### Addition  : char* bigInt_addition(char *n1, char *n2) 
    It takes two strings as an input and returns the mathematical addition (n1 + n2) of these numbers as a new string.

2. #### Subtraction: char* bigInt_subtraction(char *n1, char *n2) 
    It takes two strings as an input and returns the mathematical subtraction (n1 - n2) of these numbers as a new string.

3. #### Multiplication : char* bigInt_multiplication(char *n1, char *n2)  
    It takes two strings as an input and returns the mathematical multiplication (n1 * n2) of these numbers as a new string.

4. #### Divison : char* bigInt_divide(char *n1, char *n2) 
    It takes two strings as an input and returns the mathematical divison (n1 / n2) of these numbers as a new string.

5. #### Modulus : char* bigInt_modulus(char *n1, char *n2) 
    It takes two strings as an input and returns the mathematical modulus (n1 % n2) of these numbers as a new string.

6. #### Factorial : char* bigInt_factorial(char *n1) 
    It takes a string as an input and returns the factorial ( n1! ) of that number as a new string.

7. #### Power : char* bitInt_power(char *n1, char* n2) 
    It takes two strings as an input and returns the mathematical power (n1 ^ n2) of these numbers as a new string.

8. #### Comparison : int bigInt_compare(char *n1, char *n2)
    It takes two strings as an input and compares them. It will return  
     * 1 if n1 > n2  
     *0 if n1 = n2  
     *-1 if n1 < n2.


## Goals
The main goal of BigInt library is to be able to operate on integer values that are outside the data type limits.
