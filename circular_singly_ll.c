#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode; 
        newNode->next = head;
    }
}

struct Node *insertBegin(struct Node *head, int val)
{
    struct Node *new_node = createNode(val);
    struct Node *temp = head;

    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
        return head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }

        new_node->next = head;
        temp->next = new_node;
        head = new_node;
        return head;
    }
}

void displayList(struct Node *head)
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != head)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("%d -> Head\n", temp->data);
}

int main()
{
    struct Node *head = NULL;

    head = insertBegin(head,10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);

    displayList(head);

    head = insertBegin(head,5);
    printf("Circular linked list after inserting %d at beginning. :\n",5);
    displayList(head);

    return 0;
}
