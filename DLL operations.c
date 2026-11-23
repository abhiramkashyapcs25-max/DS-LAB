
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

struct node *createNode(int value) {
    struct node *newNode =
        (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void create(int value) {
    struct node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertLeft(int key, int value) {
    struct node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found!\n");
        return;
    }

    struct node *newNode = createNode(value);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;

    printf("Node inserted successfully.\n");
}

void deleteNode(int value) {
    struct node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Node deleted successfully.\n");
}

void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, value, key, n, i;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Create List\n");
        printf("2. Insert Left of Node\n");
        printf("3. Delete Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    create(value);
                }
                break;

            case 2:
                printf("Enter the node value: ");
                scanf("%d", &key);

                printf("Enter new value: ");
                scanf("%d", &value);

                insertLeft(key, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                deleteNode(value);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
