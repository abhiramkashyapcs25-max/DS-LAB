
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node* createNode(int value)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

void insertFirst(int value)
{
    struct node *newnode = createNode(value);
    newnode->next = head;
    head = newnode;
}

void insertEnd(int value)
{
    struct node *newnode = createNode(value);
    struct node *temp;
    if (head == NULL)
    {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void insertPosition(int value, int pos)
{
    struct node *newnode, *temp;
    int i;

    if (pos < 1)
    {
        printf("\nInvalid position!");
        return;
    }

    if (pos == 1)
    {
        insertFirst(value);
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("\nInvalid position!");
        return;
    }

    newnode = createNode(value);
    newnode->next = temp->next;
    temp->next = newnode;
}

void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("\nList is Empty!");
        return;
    }

    printf("\nLinked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

int main()
{
    int choice, value, pos;

    while (1)
    {
        printf("\n\n--- SINGLY LINKED LIST ---");
        printf("\n1. Insert at First");
        printf("\n2. Insert at Position");
        printf("\n3. Insert at End");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFirst(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(value, pos);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}
