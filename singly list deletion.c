
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void create()
{
    struct node *newnode, *temp;
    int n, i, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("\nInvalid number of nodes!");
        return;
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &value);
        newnode = (struct node*)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("\nMemory allocation failed!");
            return;
        }
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

void deleteFirst()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("\nList is Empty!");
        return;
    }

    temp = head;
    head = head->next;

    printf("\nDeleted element: %d", temp->data);

    free(temp);
}

void deleteSpecified()
{
    struct node *temp, *prev;
    int value;
    if (head == NULL)
    {
        printf("\nList is Empty!");
        return;
    }
    printf("Enter element to delete: ");
    scanf("%d", &value);
    temp = head;
    prev = NULL;
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nElement not found!");
        return;
    }
    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    printf("\nDeleted element: %d", temp->data);

    free(temp);
}

void deleteLast()
{
    struct node *temp, *prev;
    if (head == NULL)
    {
        printf("\nList is Empty!");
        return;
    }
    temp = head;
    prev = NULL;
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }
    printf("\nDeleted element: %d", temp->data);
    free(temp);
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
    int choice;
    while (1)
    {
        printf("\n\n--- SINGLY LINKED LIST DELETION ---");
        printf("\n1. Create Linked List");
        printf("\n2. Delete First Element");
        printf("\n3. Delete Specified Element");
        printf("\n4. Delete Last Element");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                deleteSpecified();
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}
