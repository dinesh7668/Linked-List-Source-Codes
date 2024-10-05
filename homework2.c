#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int traversal(node *ptr)
{
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}

node *createnode(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

struct node* insert( node* head, int newData) {
     node* current = head;
     node* beforecurrent;
     node* newnode = createnode(newData);

    // Traverse the list to find the node with data 5
    while (current != NULL && current->data != 5) {
        beforecurrent = current;
        current = current->next;
    }

        newnode->next = beforecurrent->next;
        beforecurrent->next = newnode;
    
  return head;
}

int main()
{
    node *head, *first, *second, *third, *fourth, *fifth, *six, *seven, *eight, *nine, *last;
    first = createnode(1);
    second = createnode(2);
    third = createnode(3);
    fourth = createnode(4);
    fifth = createnode(5);
    six = createnode(6);
    seven = createnode(7);
    eight = createnode(8);
    nine = createnode(9);

    head = last = first;

    head->next = second;
    last = last->next;

    second->next = third;
    last = last->next;

    third->next = fourth;
    last = last->next;

    fourth->next = fifth;
    last = last->next;

    fifth->next = six;
    last = last->next;

    six->next = seven;
    last = last->next;

    seven->next = eight;
    last = last->next;

    eight->next = nine;
    last = last->next;
    printf("\nList before inserting 20 before 5");
    traversal(head);
    head = insert(head, 20);
    printf("\nList after inserting 20 before 5");
    traversal(head);

    return 0;
}