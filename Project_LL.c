#include <stdio.h>
#include <stdlib.h>
#define size 100

typedef struct node
{
    int roll;
    int reg;
    float per;
    char name[30];
    struct node *next;
} node;

node *createnode()
{
    node* newnode = (node*)malloc(sizeof(node));
    printf("Enter student's name : ");
    scanf("%s", &newnode->name);
    printf("Enter students reg_no. : ");
    scanf("%d", &newnode->reg);
    printf("Enter students roll_no. : ");
    scanf("%d", &newnode->roll);
    printf("Enter student's percentage : ");
    scanf("%f", &newnode->per);
    newnode->next = NULL;
    return newnode;
}

node *inputStudentData(node *head, node *last)
{
    node *ptr = head;
    node *qtr = last;
    if (ptr->next == NULL)
    {
        ptr->next = createnode();
        last = ptr->next;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            last = ptr;
        }
        ptr->next = createnode();
    }
    return last;
}

node *deleteStudent(node *head, int rolll)
{
    node *temp, *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->roll == rolll)
        {
            temp = ptr;
            ptr->next = ptr->next->next;
            free(temp);
            printf(" Student with Roll no. %d Deleted Successfully\n", rolll);
        }
        else
            ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        printf("We don't have any student with roll no. %d", rolll);
    }
    return head;
}

node *deleteStudentl(node *head)
{
    node *ptr = head;
    node *last;

    while (ptr->next != NULL)
    {
        last = ptr;
        ptr = ptr->next;
    }

    if (head->next == NULL)
    {
        printf("There is no student to be deleted : \n");
    }
    else
    {
        node *temp = last->next;
        last->next = NULL;
        free(temp);
        printf("Last Student Deleted Successfully\n");
    }
    return head;
}

void updateStudent(node *head)
{
    int rolll;
    node *ptr = head;
    if (ptr->next == NULL)
    {
        printf("There is no student to be Updated : \n");
    }
    else
    {

        printf("Enter the roll no. of the student whose data is to be updated : ");
        scanf("%d", &rolll);

        while (ptr->roll != rolll && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->roll == rolll)
        {
            printf("Enter data to be updated :");
            printf("\nEnter student's name : ");
            scanf("%s", &ptr->name);
            printf("Enter students reg_no. : ");
            scanf("%d", &ptr->reg);
            printf("Enter students roll_no. : ");
            scanf("%d", &ptr->roll);
            printf("\nEnter student's percentage : ");
            scanf("%f", &ptr->per);
            printf("Data Updated Successfully !\n");
        }
        else
        {
            printf("\nRoll no. didi not match");
        }
    }
}

void displayStudent(node *head)
{
    node *ptr = head;
    if (head->next == NULL)
    {
        printf("There is noting to display .");
    }
    else
    {
        printf("\nEntered data is :");
        printf("\nName \tRoll \tReg \tPercentage.");
        while (ptr != NULL)
        {
            ptr = ptr->next;
            printf("\n%s \t%d \t%d \t%f.", ptr->name, ptr->reg, ptr->roll, ptr->per);
        }
    }
}

int main()
{
    node *head, *last;

    int choice, pick;
    head->next = NULL;
    last = head;
    ;
    int rolll, i = 0;

    while (i < size)
    {
        printf("\nStudent Database Menu:\n");
        printf("1. Insert student data \t\t2. Delete student data\n");
        printf("3. Update student data \t\t4. Display all student data\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            last = inputStudentData(head, last);
            i++;
            break;
        case 2:
            printf("1. Delete by roll no. \t\t2. Delete last added student\n");
            printf("Enter your choice: ");

            scanf("%d", &pick);
            switch (pick)
            {
            case 1:
                printf("Enter the Roll No of the student to delete: ");
                scanf("%d", &rolll);
                head = deleteStudent(head, rolll);
                break;
            case 2:
                head = deleteStudentl(head);
                break;
            default:
                printf("Only 1 & 2 are accepted ");
            }
            i--;
            break;
        case 3:
            updateStudent(head);
            break;
        case 4:

            displayStudent(head);
            break;
        default:    
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
