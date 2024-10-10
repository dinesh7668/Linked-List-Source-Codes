#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *createList(node *head, int size)
{
    node *ptr = head;
    node *temp = ptr;
    node *newnode;
    int data, i;

    for (i = 0; i < size; i++)
    {
        printf("Enter the data for node %d : ", i + 1);
        scanf("%d", &data);

        newnode = (node *)malloc(sizeof(node));
        newnode->data = data;
        newnode->next = NULL;

        if (ptr == NULL)
        {
            ptr = newnode;
        }
        else
        {
            temp->next = newnode;
        }
        temp = newnode;
    }

    return ptr;
}

void printlist(node *head)
{
    node *ptr = head;

    if (ptr->next == NULL)
    {
        printf("There is no node to be print");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

node *deleteNode_first(node *head)
{
    node *ptr = head;
    node *temp;
    if (ptr == NULL)
    {
        printf("There is no node to be deleted");
        return ptr;
    }
    else
    {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
        return ptr;
    }
}

void deleteNode_Last(node *head)
{
    node *ptr = head;
    node *temp;
    if (ptr->next == NULL)
    {
        temp = ptr->next;
        ptr = NULL;
        free(temp);
    }
    else
    {
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        temp = ptr->next->next;
        ptr->next = NULL;
        free(temp);
    }
}

node *deleteNode_Mid(node *head, int data)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == data)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("There is no node with data %d\n",data);
        return head;
    }
    prev->next = temp->next;

    free(temp);

    return head;
}

int main()
{
    node *head = NULL;
    int val, choice, size;

    printf("Enter total no. of nodes : ");
    scanf("%d", &size);

    head = createList(head, size);

    printf("\nLinked list before deletion ");
    printlist(head);
    printf("Chose an option for perform deletion \n");
    printf("1. Delete first node\t2.Dlete last node\t3.Delete node with data : \n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        head = deleteNode_first(head);
        break;
    }
    case 2:
    {
        deleteNode_Last(head);
        break;
    }
    case 3:
    {
        printf("Enter data to delete a node matching with that data : ");
        scanf("%d",&val);
        head = deleteNode_Mid(head, val);
        break;
    }
    default:
        printf("\nOnly 1 , 2 & 3 are accepted here .");
    }

    printf("Linked list after deletion ");
    printlist(head);
    return 0;
}
