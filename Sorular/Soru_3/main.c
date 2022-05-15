#include <stdio.h>
#include <stdlib.h>

//  (In a linear linked list, write a function that deletes the element in the middle of the list (free this
//memory location) (if the list has 100 or 101 elements, it will delete the 50th element). The function will
//take a list as a parameter and return the updated list.

struct node {
    int number;
    struct node * next;
};

struct node* deleteMid(struct node* head);

int main() {

    return 0;
}


struct node* deleteMid(struct node* head)
{
    struct node* p;
    struct node* previous_one;
    struct node* next_one;
    struct node* start;
    start = head;

    p = start;
    int counter = 0;
    while(p != NULL)
    {
        counter++;
        p = p->next;
    }

    p = start;

    for(int i = 0; i < (counter / 2) ; i++)
    {
        previous_one = p;
        p = p->next;
        p->next = next_one;
    }

    previous_one->next = next_one;
    free(p);

    return start;
}
