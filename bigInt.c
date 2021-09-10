#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "helper.h"
#include "bigInt.h"

char* add(char* num1, char* num2) {

    // If one of the numbers is negative then subtracting them
    if(num1[0] == '-' && num2[0] != '-') {
        return subtract(num2, removeNegativeSign(num1));
    }
    else if(num1[0] != '-' && num2[0] =='-') {
        return subtract(num1, removeNegativeSign(num2));
    }
    // If both the numbers are positive or both are negative then adding them
    else {

        LinkedList *ll_num1 = convertStringToReversedLinkedList(num1), *ll_num2 = convertStringToReversedLinkedList(num2);
        LinkedList *ll_output = createLinkedList();

        Node *current1 = ll_num1 -> head, *current2 = ll_num2 -> head;

        int a , b , carry = 0;

        while(current1 != NULL || current2 != NULL) {

            a = 0, b = 0;

            if(current1 != NULL) {
                a = current1 -> data;
            }
            if(current2 != NULL) {
                b = current2 -> data;
            }

            Node* newNode = createNode((a + b + carry) % 10);
            newNode -> next = ll_output -> head;
            ll_output -> head = newNode;

            carry = (a + b + carry) / 10;

            if(current1 != NULL) {
                current1 = current1 -> next;
            }
            if(current2 != NULL) {
                current2 = current2 -> next;
            }
        }

        // If carry is left then adding that to the output
        if(carry > 0) {
            Node* newNode = createNode(carry);
            newNode -> next = ll_output -> head;
            ll_output -> head = newNode;
        }

        // If both the numbers are negative then the output will also be negative
        if(ll_num1 -> isNeg && ll_num2 -> isNeg) {
            ll_output -> isNeg = 1;
        }

        char *result = convertLinkedListToString(ll_output);

        freeLinkedList(ll_num1);
        freeLinkedList(ll_num2);
        freeLinkedList(ll_output);

        return result;
    }
}

// computeSubtract only works with the positive numbers so the driver code for it is in subtract function
char* computeSubtract(char *larger, char *smaller) {

    LinkedList *ll_larger = convertStringToReversedLinkedList(larger), *ll_smaller = convertStringToReversedLinkedList(smaller);
    Node *currentLarger = ll_larger -> head, *currentSmaller = ll_smaller -> head;

    LinkedList *output = createLinkedList();

    int a, b; // representing current digit of each ll
    int borrow = 0; // acts as a flag that a digit was borrowed by a number before it

    while(currentLarger != NULL || currentSmaller != NULL) {

        a = 0, b = 0;

        if(currentLarger != NULL) {
            a = currentLarger -> data;
            currentLarger = currentLarger -> next;
        }
        if(currentSmaller != NULL) {
            b = currentSmaller -> data;
            currentSmaller = currentSmaller -> next;
        }

        if(borrow) {
            borrow = 0;
            a -= 1;
        }

        if(a < b) {
            borrow = 1;
            a += 10;
        }

        Node* newNode = createNode(a - b);
        newNode -> next = output -> head;
        output -> head = newNode;
    }

    //Removing zeros from front
    Node* currentOutput = output -> head;

    while(currentOutput -> data == 0 && currentOutput -> next != NULL) {
        currentOutput = currentOutput -> next;
    }

    output -> head = currentOutput;

    char *result = convertLinkedListToString(output);

    freeLinkedList(ll_larger);
    freeLinkedList(ll_smaller);
    freeLinkedList(output);

    return result;
}

char* subtract(char* num1, char *num2) {

    int comparison = compare(num1, num2);

    if(comparison == 0) {
        return "0"; // Both numbers are equal
    }

    if(num1[0] == '-' && num2[0] != '-') {
        return add(num1, addNegativeSign(num2));
    }
    else if(num1[0] != '-' && num2[0] == '-') {
        return add(num1, removeNegativeSign(num2));
    }
    else if(num1[0] != '-' && num2[0] != '-') {
        if(comparison == 1) {
            return computeSubtract(num1, num2);
        }
        else {
            return addNegativeSign(computeSubtract(num2, num1));
        }
    }
    else {
        //Both are negative
        if(comparison == 1) {
            return computeSubtract(removeNegativeSign(num2), removeNegativeSign(num1));
        }
        else {
            return addNegativeSign(computeSubtract(removeNegativeSign(num1), removeNegativeSign(num2)));
        }
    }
}

char* multiply(char *num1, char *num2) {

    LinkedList *ll_num1 = convertStringToReversedLinkedList(num1), *ll_num2 = convertStringToReversedLinkedList(num2);
    LinkedList *reversedOutput = createLinkedList();
    reversedOutput -> head = createNode(INT_MIN); // representing end of linked list

    Node *current1 = ll_num1 -> head, *current2 = ll_num2 -> head;
    Node *currentOutput = reversedOutput -> head, *resultStart = reversedOutput -> head;

    int a, b, carry;

    while(current2 != NULL) {

        carry = 0;
        b = current2 -> data;
        currentOutput = resultStart; // representing start of addition at every iteration

        while(current1 != NULL) {

            a = current1 -> data;
            int value = a * b + carry;

            if(currentOutput -> data == INT_MIN) {
                currentOutput -> next = createNode(INT_MIN);
                currentOutput -> data = value % 10;
            }
            else {
                currentOutput -> data += value % 10;
            }

            carry = value / 10 + currentOutput -> data / 10;
            currentOutput -> data = currentOutput -> data % 10;

            current1 = current1 -> next;
            currentOutput = currentOutput -> next;
        }

        while(carry > 0) {

            if(currentOutput -> data == INT_MIN) {
                currentOutput -> next = createNode(INT_MIN);
                currentOutput -> data = carry % 10;
            }
            else {
                currentOutput -> data += carry % 10;
            }

            carry = carry / 10;
        }

        resultStart = resultStart -> next;
        current1 = ll_num1 -> head;
        current2 = current2 -> next;
    }

    // Removing the dummy node(INT_MIN)
    currentOutput = reversedOutput -> head;
    while(currentOutput -> next -> next != NULL) {
        currentOutput = currentOutput -> next;
    }
    currentOutput -> next = NULL;

    // If one of the numbers is negative then the output will be negative else it would be positive
    if((ll_num1 -> isNeg && (!ll_num2 -> isNeg)) || ((!ll_num1 -> isNeg) && ll_num2 -> isNeg)) {
        reversedOutput -> isNeg = 1;
    }

    reverseLinkedList(reversedOutput);

    char* result = convertLinkedListToString(reversedOutput);

    freeLinkedList(ll_num1);
    freeLinkedList(ll_num2);
    freeLinkedList(reversedOutput);

    return result;
}

char* factorial(char* num) {

    char* result = (char*) malloc(sizeof(char) * 1000);
    result[0] = '1';
    result[1] = '\0';

    char* buffer = (char*) malloc(sizeof(char) * 1000);
    int length;

    for(int i = 2; i <= atoi(num) ; i++) {

        length = snprintf(NULL, 0, "%d", i);

        snprintf(buffer, length + 1, "%d", i);
        buffer[length] = '\0';

        result = multiply(result, buffer);
    }

    free(buffer);

    return result;
}

int compare(char* num1, char *num2) {

    int num1_isNeg = 0, num2_isNeg = 0;

    if(num1[0] == '-') {
        num1_isNeg = 1;
    }
    if(num2[0] == '-') {
        num2_isNeg = 1;
    }

    // If one of the numbers is negative and other is positive then the positive one is greater
    if(!num1_isNeg && num2_isNeg) {
        return 1;
    }
    else if(num1_isNeg && !num2_isNeg) {
        return -1;
    }

    // After this both numbers are either positive or both are negative

    //If number is positive than greater length means greater value and if it is negative then greater length means lesser value
    if(strlen(num1) > strlen(num2)) {

        if(num1_isNeg && num2_isNeg) {
            return -1;
        }
        else {
            return 1;
        }
    }
    else if(strlen(num1) < strlen(num2)) {

        if(num1_isNeg && num2_isNeg) {
            return 1;
        }
        else {
            return -1;
        }
    }

    // If both the lengths are equal then compare each digit

    for(int i = 0 ; i < strlen(num1) ; i++) {

        if(num1[i] > num2[i]) {

            if(num1_isNeg && num2_isNeg) {
                return -1;
            }
            else {
                return 1;
            }
        }
        else if(num1[i] < num2[i]) {

            if(num1_isNeg && num2_isNeg) {
                return 1;
            }
            else {
                return -1;
            }
        }
    }

    return 0; // Both are same numbers
}




char* power(char* num1, char* num2) {

    if(num2[0] == '-') {
        return NULL;
    }

    char* result = (char*) malloc(sizeof(char) * 1000);
    result[0] = '1';
    result[1] = '\0';

    while(num2[0] != '0') {
        num2 = subtract(num2, "1");
        result = multiply(result, num1);
    }

    return result;
}

char* divide(char* num1, char* num2) {

    int num1_isNeg = 0, num2_isNeg = 0;

    if(num1[0] == '-') {
        num1_isNeg = 1;
        num1 = removeNegativeSign(num1);
    }
    if(num2[0] == '-') {
        num2_isNeg = 1;
        num2 = removeNegativeSign(num2);
    }

    char* quotient = (char*) malloc(sizeof(char) * 1000);
    quotient[0] = '0';
    quotient[1] = '\0';

    while(compare(num1, num2) >= 0) {
        num1 = subtract(num1, num2);
        quotient = add(quotient, "1");
    }

    // If one of them was negative then the result will be negative
    if(((!num1_isNeg && num2_isNeg) || (num1_isNeg && !num2_isNeg)) && quotient[0] != '0') {
        quotient = addNegativeSign(quotient);
    }

    return quotient;
}

char* modulus(char* num1, char* num2) {

    int num1_isNeg = 0, num2_isNeg = 0;

    if(num1[0] == '-') {
        num1_isNeg = 1;
        num1 = removeNegativeSign(num1);
    }
    if(num2[0] == '-') {
        num2_isNeg = 1;
        num2 = removeNegativeSign(num2);
    }

    while(compare(num1, num2) >= 0) {
        num1 = subtract(num1, num2);
    }

    if(((num1_isNeg && num2_isNeg) || (num1_isNeg && !num2_isNeg)) && num1[0] != '0') {
        num1 = addNegativeSign(num1);
    }

    return num1;
}


