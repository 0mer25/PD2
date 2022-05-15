#include <stdio.h>
#include <stdlib.h>


//  (In a linear linked list, write a function named changeFirstAndLast that swaps the node at the end of the
//list and the node at the beginning of the list. The function will take a list as a parameter and return the
//updated list.

struct node {
    int number;
    struct node * next;
};

struct node* changeFirstAndLast(struct node* head);


int main() {

    return 0;
}


struct node* changeFirstAndLast(struct node* head)
{
    struct node* p;
    struct node* q;
    struct node* first_Node;
    struct node* second_Node;

    p = head;
    q = head;
    first_Node = head;
    second_Node = head->next;

    while(p->next != NULL)
    {
        q = p;
        p = p->next;
    }

    p->next = second_Node;
    q->next = first_Node;
    first_Node->next = NULL;

    return p;

}
