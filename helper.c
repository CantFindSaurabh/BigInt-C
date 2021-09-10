#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "helper.h"



// Node Functions
Node* createNode(int value) {

    Node *node = (Node*) malloc (sizeof(Node));

    node -> next = NULL;
    node -> data = value;

    return node;
}

void freeNode(Node* node) {

    if(node == NULL) {
        return;
    }

    free(node);
}



// LinkedList Functions
LinkedList* createLinkedList() {

    LinkedList *ll = (LinkedList*) malloc (sizeof(LinkedList));

    ll -> head = NULL;
    ll -> isNeg = 0;

    return ll;
}

void freeLinkedList(LinkedList* ll) {

    if(ll -> head == NULL) {
        return;
    }

    Node* prev;

    while(ll -> head != NULL) {

        prev = ll -> head;
        ll -> head = ll -> head -> next;

        free(prev);
    }

    free(ll);
}

void printLinkedList(LinkedList* ll) {

    if(ll -> head == NULL) {
        return;
    }

    Node *current = ll -> head;

    if(ll -> isNeg) {
        printf("-");
    }

    while(current != NULL) {

        printf("%d", current -> data);

        current = current -> next;
    }

    printf("\n");
}

void reverseLinkedList(LinkedList *ll)
{
    if(ll -> head == NULL) {
        return;
    }

    Node* left = NULL, *current = ll -> head, *right;

    while (current != NULL) {

        right = current -> next;

        current -> next = left;
        left = current;
        current = right;
    }

    ll -> head = left;
}

// Converts string into a linked list with the characters in reverse order
LinkedList* convertStringToReversedLinkedList(char* str) {

    int len = strlen(str) ;

    if(str[len] == '\0') {
        len--;
    }
    if(str[len]  == '\n') {
        len--;
    }

    LinkedList *ll = createLinkedList();
    ll -> head = createNode(str[len] - '0');

    Node *current = ll -> head;

    for(int i = len - 1 ; i >= 0 && str[i] != '-'; i--) {
        current -> next = createNode(str[i] - '0');
        current = current -> next;
    }

    // marking negative
    if(str[0] == '-') {
        ll -> isNeg = 1;
    }

    return ll;
}

char* convertLinkedListToString(LinkedList* ll) {

    if(ll -> head == NULL) {
        return NULL;
    }

    Node* current = ll -> head;

    int pointer = 0, capacity = 100;

    char* output = (char*) calloc(capacity, sizeof(char));

    if(ll -> isNeg) {
        output[0] = '-';
        pointer++;
    }

    while(current != NULL) {

        // Reallocating capacity if output size becomes greater than capacity
        if(pointer == capacity - 10){
            capacity *= 2;
            output = (char*) realloc(output, sizeof(char) * capacity);
        }

        output[pointer] = current -> data + '0';
        pointer++;

        current = current -> next;
    }

    output[pointer] = '\0';

    return output;
}


// String Functions
char* addNegativeSign(char *num) {

    char* str = (char*) malloc(sizeof(char) * (strlen(num) + 2));

    str[0] = '-';

    for(int i = 1 ; i <= strlen(str) + 1 ; i++) {
        str[i] = num[i - 1];
    }

    return str;
}

char* removeNegativeSign(char *num) {

    char* str = (char*) malloc(sizeof(char) * (strlen(num) - 1));

    for(int i = 1 ; i <= strlen(num) ; i++) {
        str[i - 1] = num[i];
    }

    return str;
}
