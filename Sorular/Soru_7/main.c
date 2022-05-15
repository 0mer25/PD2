#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//  Write a function that takes two parameters head (list name) and age (given student age). The function
//deletes node (free this memory location) by finding the second node with the given age value in the list.
//Write the required function using the prototype given below.



struct node {
    int age;
    struct node * next;
};
typedef struct node node;
node* deleteNode(node* , int);

int main() {

    return 0;
}

node* deleteNode(node* head, int age)
{
    node* p;
    node* previous_one;
    node* next_one;
    bool found = false;
    bool go = true;
    p = head;

    while(go)
    {
        if((p->age != age))
        {
            previous_one = p;
            p = p->next;
        }
        else
        {
            if(found)
            {
                next_one = p->next;
                go = false;
            }
            else
            {
                found = true;
                previous_one = p;
                p = p->next;
            }
        }
    }

    previous_one->next = next_one;
    free(p);
}