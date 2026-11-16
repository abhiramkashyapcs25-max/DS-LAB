#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;
struct Node *front = NULL;
struct Node *rear = NULL;

void push() {
    int value;
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Element pushed successfully\n");
}

void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", top->data);

    top = top->next;
    free(temp);
}

void displayS() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
void enqueue() {
    int value;
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Element inserted successfully\n");
}
void dequeue() {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", front->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void displayQ() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- STACK and QUEUE MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Enqueue\n");
        printf("4. Dequeue\n");
        printf("5. Display stack\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: enqueue(); break;
            case 4: dequeue(); break;
            case 5: displayS(); break;
            case 6: displayQ(); break;
            case 7: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}
