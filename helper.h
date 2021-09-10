#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct llist {
    struct node* head;
    int isNeg;
} LinkedList;

// Node Functions
Node* createNode(int value);

void freeNode(Node* node);


// LinkedList Functions
LinkedList* createLinkedList();

void freeLinkedList(LinkedList* ll);

void printLinkedList(LinkedList* ll);

void reverseLinkedList(LinkedList *ll);

LinkedList* convertStringToReversedLinkedList(char* str); // Converts string into a linked list with the characters in reverse order

char* convertLinkedListToString(LinkedList* ll);



// String Functions
char* addNegativeSign(char *num);

char* removeNegativeSign(char *num);


#endif
