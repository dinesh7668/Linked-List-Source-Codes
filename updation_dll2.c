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

        printf("Enter the data for node %d : ", i);
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

struct Node * updateNode(struct Node *head, int node_val, int newval)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    struct Node *temp = head;

    while (temp != NULL)
    {

        if (temp->data == node_val)
        {
            temp->data = newval;
            printf("Node with data %d updated to %d.\n",node_val, newval);
            printList(head);
            return head;
        }

        temp = temp->next;
    }

    printf("Node with data %d list mein hai hi nhi\n",node_val);
    return head;
}

int main()
{
    struct Node *head;
    int sz, val, node_data;

    printf("Enter the total no. of nodes : ");
    scanf("%d", &sz);

    head = createNodes(sz);

    printf("List - :");
    printList(head);

    printf("Enter the data and the new data jisse node ko update karna hai : ");
    scanf("%d%d",&node_data,&val);

    head = updateNode(head,node_data,val);

    return 0;
}
