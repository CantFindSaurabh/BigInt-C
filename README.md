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

## Usage

#### Using Makefile:
* Include **bigInt.h** in your c file.
* Run Command on terminal : **make final** (default filename is main.c)

Or

* Include **bigInt.h** in your c file.
* Command for compiling : **gcc (file_name) bigInt.c helper.c -o main**


## Design and Specifications 

It consists of two files **bigInt.c** (containing all the operations) and **helper.c** (containing the functions for manipulating linkedlist and strings).

All the function of library takes a string as an input then internally converts it into a linkedlist with each node storing each digit.
The string is stored in reverse order so as to able to operate easily.

Input String : "12345"  
LinkedList : 5 -> 4 -> 3 -> 2 -> 1 -> NULL

After operating on the linkedlist, a new string with output number is created and returned.

*****
| Operation | Function Signature | Overview |
| ------------- |:-------------:|:-------------:|
|**Addition**  | char* add(char *n1, char *n2) |It takes two strings as an input and returns the addition (n1 + n2) of these numbers as a new string. |
| **Subtraction** | char* subtract(char *n1, char *n2) |It takes two strings as an input and returns the subtraction (n1 - n2) of these numbers as a new string. |
| **Multiplication** | char*  multiply(char *n1, char *n2) | It takes two strings as an input and returns the multiplication (n1 * n2) of these numbers as a new string. |
| **Divison** | char* divide(char *n1, char *n2) | It takes two strings as an input and returns the divison (n1 / n2) of these numbers as a new string. |
| **Modulus** | char* modulus(char *n1, char *n2) | It takes two strings as an input and returns the modulus (n1 % n2) of these numbers as a new string. |
|**Factorial** | char* factorial(char *n1) | It takes a string as an input and returns the factorial ( n1! ) of that number as a new string. |
|**Power** | char* power(char *n1, char *n2) | It takes two strings as an input and returns n1 raised to power n2 (n1 ^ n2) as a new string. |
| **Comparison** | int compare(char *n1, char *n2) |It takes two strings as an input and compares them. It will return <ul><li> 1 if n1 > n2  </li><li> 0 if n1 = n2  </li><li> -1 if n1 < n2</li> </ul>|

## Goals
The main goal of BigInt library is to be able to operate on integer values that are outside the data type limits.

