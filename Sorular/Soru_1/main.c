#include <stdio.h>
#include <stdlib.h>


//  Adding the odd numbers to the beginning of the list and even numbers to the end of the list until -1 is
// entered from keyboard.

struct node{
    int number;
    struct node* next;
};

struct node* start = NULL;
struct node* q;

struct node* createNewNode(int number);
void addLast(int number);
void addFirst(int number);
void print();


int main() {
    int number;

    while(1)
    {
        printf("Number = ");
        scanf("%d" , &number);

        if(number == -1)
        {
            break;
        }
        else
        {
            if((number % 2) == 0)
            {
                addLast(number);
            }
            else
            {
                addFirst(number);
            }
        }
    }

    // Yazdırma fonksiyonu
    // print();

    return 0;
}


struct node* createNewNode(int number)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}


void addLast(int number)
{
    struct node* toBeAdd = createNewNode(number);
    if(start == NULL)
    {
        start = toBeAdd;
    }
    else
    {
        struct node* temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = toBeAdd;
    }
}


void addFirst(int number)
{
    struct node* toBeAdd = createNewNode(number);
    if(start == NULL)
        start = toBeAdd;
    else
    {
        struct node* temp = start;
        start = toBeAdd;
        toBeAdd->next = temp;
    }
}

void print()
{
    q = start;
    while(q != NULL) {

        printf("%d ",q->number);
        q = q->next;

    }
}




