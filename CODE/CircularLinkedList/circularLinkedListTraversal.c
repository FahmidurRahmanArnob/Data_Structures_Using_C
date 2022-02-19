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

//Insertion in Circular Linked List..
void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;

    /*
    printf("Element is: %d\n", ptr->data);
    ptr = ptr -> next;

    // uporer duita line er drkr nai jodi do while loop use kori..
    // uporer duita line just ptr re manually head theikka ekta node samne agaya dey..jate koira condition ta meet up na hoy and ekbar traversal complete hoy..

    while(ptr != head){
        printf("Element is: %d\n", ptr->data);
        ptr = ptr -> next;
    }

    // and do-while loop dile uporer oi dui line lagbe na karon ...
    // do-while to to ekbar emnei cholbo 
    // so ekbar jodi emnei chole taile first element to print hobei and ptr ek node samne agaya jabe
    // second time run howar jonno condition met howa jaa 
    // first time run howar sathe sathe met hobe so ei karone oi barti dui line er code lekhar dorkar nai 
    // easily do-while loop diya kaaj hoiya jaitase ..

    */

    do{
        printf("Element is => %d\n", ptr->data);
        ptr = ptr -> next;
    }while(ptr != head);
}

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

    linkedListTraversal(head);

    return 0;
}