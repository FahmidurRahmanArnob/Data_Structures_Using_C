#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; //This is a self referencing structure; struct Node type er pointer and ei type structure e point korbe eita
};

int main()
{

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
    head->data = 4;
    head->next = second;

    //This Linkes Second and Third Nodes..
    second->data = 3;
    second->next = third;

    //This Linkes Third and Fourth Nodes..
    third->data = 6;
    third->next = fourth;

    //This Linkes Fourth and Fifth nodes ..
    fourth->data = 1;
    fourth->next = NULL;

    return 0;
}