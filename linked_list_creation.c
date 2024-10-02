#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_node(int val)
{
    struct node *ptr, *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    ptr = new_node;
    ptr->data = val;
    ptr->next = NULL;

    return ptr;
}

void traversal(struct node *ptr)
{
    printf("\nThe data in linked list is");
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head, *last, *first_node, *second_node, *third_node;
    first_node = create_node(5);
    second_node = create_node(10);
    third_node = create_node(15);

    head = first_node;
    last = head;

    last->next = second_node;
    last = last->next;

    last->next = third_node;
    last = last->next;

    // printf("\nfirst node has %d", first_node->data);
    // printf("\nsecond node has %d", second_node->data);
    // printf("\nthird node has %d", third_node->data);

    traversal(head);
    return 0;
}
