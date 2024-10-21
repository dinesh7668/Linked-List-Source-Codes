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

struct Node * updateNode(struct Node *head, int ind, int val)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    struct Node *temp = head;
    int count = 0;

    while (temp != NULL && count <= ind)
    {
        count++;
        temp = temp->next;

        if (count == ind)
        {
            temp->data = val;
            printf("Node at index %d updated to %d.\n", ind, val);
            printList(head);
            return head;
        }

    }

    printf("Index value %d available no. of nodes se jyada hai\n",ind);
    return head;
}

int main()
{
    struct Node *head;
    int sz, val, ind;

    printf("Enter the total no. of nodes : ");
    scanf("%d", &sz);

    head = createNodes(sz);

    printf("List - :");
    printList(head);

    printf("Enter the node's index value and the data by which node will be updated : ");
    scanf("%d%d", &ind, &val);

    head = updateNode(head, ind, val);

    return 0;
}
