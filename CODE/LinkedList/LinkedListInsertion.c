#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;  //This is a self referencing structure; struct Node type er pointer and ei type structure e point korbe eita 
};

void linkedListTraversal(struct Node *ptr){
    // printf("Starting Traversing ....\n\n");
    while(ptr != NULL){
        printf("Element => %d\n", ptr->data);
        ptr = ptr->next;
    }
    // printf("\nThis was your Linked List Traversal.\nGood Bye\n");
}

//Case 1: Insertion at the beginning;
struct Node *insertAtBeginning(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;//now ptr is the new head and we're returning it;
}

//Case 2: Insert at index;
struct Node *insertInBetween(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));

    struct Node *p = head;
    int i = 0;
    while(i != index - 1){
        p = p->next;
        i++;
    }
    ptr->data = data;//Notun ana node er data re set koira dilo..
    ptr->next = p->next;//ptr points towards the next node now;
    p->next = ptr; //previous nodes pointer got connected with the ptr;
    return head;//puraton head e notun head;
    
}

//Case 3: Insert at the End of the List...
struct Node *insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    
    while(p->next != NULL){
        p = p->next; //jotokkhon na porjonto null ashtese P next node e jaite thakbe..
    }

    p->next = ptr; //Now P points to the ptr;
    ptr->next = NULL; // ptr has become the new last node and points to NULL;
    return head; // Head is the same as before and we just return it; 

}

//Case 4: Insert After a Node (suppose tmre ekta pointer diye dise and boltese j ei pointer er pore insert koro ekta value... here we'are doint exactly that.. giver pointer is "ptr" and insert value is "q")

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode -> next = ptr;//ek node er address ami already jani which is prevNode..ei karone ami oi prevNode er next re ptr er dike point koraya dilam..

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

    printf("\nBefore Inserting any value in the list.\n");
    linkedListTraversal(head); //calls the function and we passed head and that's how it prints all the values.

    //now we'll talk about insertion....
    // head = insertAtBeginning(head, 100);
    // head = insertInBetween(head, 600, 1);
    // head = insertAtEnd(head, 600);
    head = insertAfterNode(head, second, 4555);
    printf("\nAfter inserting a value in the list.\n");

    linkedListTraversal(head);

    return 0;
}