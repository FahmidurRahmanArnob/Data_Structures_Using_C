#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node * next;
};

//Traversal Code :- 
void linkedListTraversal(struct Node *ptr){
    // printf("Starting Traversing ....\n\n");
    while(ptr != NULL){
        printf("Element => %d\n", ptr->data);
        ptr = ptr->next;
    }
    // printf("\nThis was your Linked List Traversal.\nGood Bye\n");
}

//case 1: deleting the first Node..
struct Node *deleteFirst(struct Node * head){
    struct Node *ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

//Case 2: Delete at index;
struct Node *deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head -> next;
    for(int i = 0;i < index - 1; i++){

        p = p -> next;
        q = q -> next;
    }
    p -> next = q -> next;
    free(q);
    return head;
}

//case 3:Delete the End Node..
struct Node *DeleteEndNode(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

//case 4: Delete a node with a given value:
struct Node *deleteWithGivenValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head -> next;

    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}

int main(){

    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    struct Node * fifth;

    //Allocate memory for nodes in the linked list in head(Dynamic Memory Allocation korsi eikhane)
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
    fifth = (struct Node *) malloc(sizeof(struct Node));

    //This Linkes First and Second Nodes..
    head -> data = 4;
    head -> next = second;

    //This Linkes Second and Third Nodes..
    second -> data = 3;
    second -> next = third;

    //This Linkes Third and Fourth Nodes..
    third -> data = 8;
    third -> next = fourth;

    //This Linkes Fourth and Fifth Nodes..
    fourth -> data = 1;
    fourth -> next = fifth;

    //This terminates the list at the fifth node..
    fifth -> data = 5;
    fifth -> next = NULL;


    printf("\nBefore Deleting a Node:- \n");
    linkedListTraversal(head);

    printf("\nAfter Deleting a Node:- \n");
    // head = deleteFirst(head);

    // int i;
    // printf("Enter a index that you want to delete: \n");
    // scanf("%d", &i);
    // head = deleteAtIndex(head, i);

    // head = DeleteEndNode(head);

    head = deleteWithGivenValue(head, 1);
    linkedListTraversal(head);

    return 0;
}