
#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

void insert()
{
    int value;
    if ((rear + 1) % SIZE == front)
    {
        printf("\nQueue Overflow!");
    }
    else
    {
        printf("Enter the element: ");
        scanf("%d", &value);
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("\nElement inserted successfully.");
    }
}

void delete()
{
    if (front == -1)
    {
        printf("\nQueue is Empty!");
    }
    else
    {
        printf("\nDeleted element: %d", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}
void display()
{
    int i;

    if (front == -1)
    {
        printf("\nQueue is Empty!");
    }
    else
    {
        printf("\nCircular Queue elements are: ");

        i = front;
        while (1)
        {
            printf("%d ", queue[i]);

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n--- CIRCULAR QUEUE MENU ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting program...");
                return 0;

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}
