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

struct Node * searching(struct Node* head,int val)
{
    int count = 0;
    struct Node * temp = head;

    if(temp == NULL)
    {
        printf("List is Empty\n");
        return temp;
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data == val)
            {
                printf("The node with data %d is at %d position",val,count+1);
            return head;
            }
            count++;
            temp = temp->next;
        }
        printf("Node with data %d does not exist in the list",val);
        return head;
    }
}

int main()
{
    struct Node *head;
    int sz,search;

    printf("Enter the total no. of nodes : ");
    scanf("%d", &sz);

    head = createNodes(sz);

    printf("List - :");
    printList(head);

    printf("Enter the node value to perform search  : ");
    scanf("%d",&search);

     head = searching(head,search);

    return 0;
}
