#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;  //This is a self referencing structure; struct Node type er pointer and ei type structure e point korbe eita 
};

void linkedListTraversal(struct Node *ptr){
    printf("Starting Traversing ....\n\n");
    while(ptr != NULL){
        printf("Element => %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\nThis was your Linked List Traversal.\nGood Bye\n");
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
    head -> data = 7;
    head -> next = second;

    //This Linkes Second and Third Nodes..
    second -> data = 11;
    second -> next = third;

    //This Linkes Third and Fourth Nodes..
    third -> data = 66;
    third -> next = fourth;

    //This Linkes Fourth and Fifth Nodes..
    fourth -> data = 78;
    fourth -> next = fifth;

    //This terminates the list at the fifth node..
    fifth -> data = 89;
    fifth -> next = NULL;

    linkedListTraversal(head);

    return 0;
}