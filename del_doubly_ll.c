
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node *createlist(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *last = head;

    if (head == NULL)
    {
        return newNode;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
    return head;
}

struct Node *createNodes(int n)
{
    struct Node *head = NULL;
    int val;

    for (int i = 1; i <= n; i++)
    {

        printf("Enter the data for node %d ", i);
        scanf("%d", &val);
        head = createlist(head, val);
    }

    return head;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *deleteNodeBefore(struct Node *head, int data)
{
    struct Node *temp = head;
    struct Node *nodeToDelete;

    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->prev == NULL)
    {
        printf("No node exists before the node with data %d.\n", data);
        return head;
    }

    nodeToDelete = temp->prev;

    if (nodeToDelete->prev == NULL)
    {
        head = nodeToDelete->next;
        head->prev = NULL;
    }
    else
    {
        nodeToDelete->prev->next = nodeToDelete->next;
        if (nodeToDelete->next != NULL)
        {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }
    }

    free(nodeToDelete);

    printf("List after deletion is - : ");
    printList(head);
    return head;
}

int main()
{
    struct Node *head;
    int sz,val;

    printf("Enter the total no. of nodes : ");
    scanf("%d", &sz);

    head = createNodes(sz);
  
    printf("List before deletion - :");
    printList(head);
    
    printf("Enter the data to delete node before the data : ");
    scanf("%d",&val);

    deleteNodeBefore(head,val);


    return 0;
}
