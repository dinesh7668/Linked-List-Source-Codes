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

    printf("Enter the data for 5 nodes : ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &val);
        head = createlist(head, val);
    }

    return head;
}

void middleNode(struct Node *head)
{
    struct Node *temp = head;
    struct Node *curr = head;
    int count = 0;
    if (temp == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        int i = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (count % 2 == 0)
        {
            count = count / 2;
            while (i != count)
            {
                curr = curr->next;
                i++;
            }
            printf("Middle node contains %d\n", curr->data);
        }
        else
        {
            count = count / 2;
            while (i != count)
            {
                curr = curr->next;
                i++;
            }
            printf("Middle node contains %d\n", curr->data);
        }
    }
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

int main()
{
    struct Node *head;
    int sz;

    printf("Enter the total no. of nodes : ");
    scanf("%d", &sz);

    head = createNodes(sz);

    printf("List - :");
    printList(head);

    middleNode(head);

    return 0;
}
