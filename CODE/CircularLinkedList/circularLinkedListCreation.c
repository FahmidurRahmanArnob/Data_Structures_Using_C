#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node * fifth;

    //Allocate memory for nodes in the linked list in head(Dynamic Memory Allocation korsi eikhane)
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *) malloc(sizeof(struct Node));

    //This Linkes First and Second Nodes..
    head->data = 7;
    head->next = second;

    //This Linkes Second and Third Nodes..
    second->data = 11;
    second->next = third;

    //This Linkes Third and Fourth Nodes..
    third->data = 66;
    third->next = fourth;

    //This Linkes Fourth and Fifth nodes ..
    fourth->data = 78;
    fourth->next = fifth;

    //This terminates the list at the fifth node..
    fifth -> data = 89;
    fifth -> next = head;

    return 0;
}