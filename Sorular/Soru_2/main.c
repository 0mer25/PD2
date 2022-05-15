#include <stdio.h>
#include <stdlib.h>

//  A singly linear list stores integer values in each node and has multiple nodes. Write a function using given
//prototype below. This function cuts the last node of the list and adds it to the beginning as first node. It
//takes beginning address of the list as a parameter and returns the updated list.

struct node {
    int number;
    struct node * next;
};

struct node* cutlastaddhead(struct node* head);


int main() {

    return 0;
}


struct node* cutlastaddhead(struct node* head)
{
    struct node* p;
    struct node* q;

    p = head;

    while(p->next != NULL)
    {
        q = p;
        p = p->next;
    }

    p->next = head;
    q->next = NULL;


    return p;
}