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

//Traversal in Circular Linked List..
void linkedListTraversal(struct Node *head){
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

    struct Node *ptr = head;
    do{
        printf("Element is => %d\n", ptr->data);
        ptr = ptr -> next;
    }while(ptr != head);
}

//Insertion in Circular Linked List...
struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));//jeikhane insert korte chai oine point korbe ei pointer ta;
    ptr->data = data;

    struct Node * p = head -> next;
    while(p->next != head){
        p = p->next;//samne nite thaktesi p re jotokkhon porjonto na p er next head aya portase mane basically p last e na jaitase totokkhon...
    }
    //at this point p points to the last node of this circular linked list..
    p->next = ptr;//last node pointing towards ptr;
    ptr->next = head;//ptr er next pointing towards head;
    head = ptr;//ptr becomes the new head;
    return head;//returning the new head;
}

int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //Allocate memory for nodes in the linked list in head(Dynamic Memory Allocation korsi eikhane)
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //This Linkes First and Second Nodes..
    head->data = 3;
    head->next = second;

    //This Linkes Second and Third Nodes..
    second->data = 5;
    second->next = third;

    //This Linkes Third and Fourth Nodes..
    third->data = 7;
    third->next = fourth;

    //This terminates the list at the fourth node..
    fourth->data = 9;
    fourth->next = head;

    printf("\nBefore Inserting a value into the Circular Linked List:- \n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 80);
    printf("After inserting a value into the Circular Linked List:\n");
    linkedListTraversal(head);

    return 0;
}