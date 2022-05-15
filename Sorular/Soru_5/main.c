#include <stdio.h>
#include <stdlib.h>

//  A singly linear list stores integer values in each node and has multiple nodes. Write a function using given
//prototype below. This function cuts the first node of the list and adds it to the end as last node. It takes
//beginning address of the list as a parameter and returns the updated list.

struct node {
    int number;
    struct node * next;
};

struct node* cutheadaddlast(struct node* head);

int main() {

    return 0;
}


struct node* cutheadaddlast(struct node* head)
{
    struct node* p;
    struct node* q;
    struct node* start;

    start = head;
    q = head->next;
    p = head;

    while(p->next != NULL)
    {
        p = p->next;
    }

    start->next = NULL;
    p->next = start;

    return q;

}