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

node *insertbeg(node *head, int val)
{
    node * newnode = createnode(val);
    newnode->next = head;
    head = newnode;
    return head;
}

int main()
{
    node *first, *head, *last, *sec, *third, *fourth;
    first = createnode(1);
    sec = createnode(2);
    third = createnode(3);
    fourth = createnode(4);

    head = first;
    last = head;

    head->next = sec;
    last = last->next;

    sec->next = third;
    last = last->next;

    third->next = fourth;
    last = last->next;
    fourth->next = NULL;

    head = insertbeg(head, 50);
    traversal(head);
    return 0;
}