

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

void insert(struct node **head, int value) {
    struct node *newNode =
        (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

void sort() {
    struct node *i, *j;
    int temp;

    for (i = head1; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("List sorted successfully!\n");
}

void reverse() {
    struct node *prev = NULL;
    struct node *current = head1;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head1 = prev;

    printf("List reversed successfully!\n");
}

void concatenate() {
    if (head1 == NULL) {
        head1 = head2;
    }
    else {
        struct node *temp = head1;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = head2;
    }

    head2 = NULL;

    printf("Lists concatenated successfully!\n");
}

int main() {
    int choice, n, value, i;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Create First Linked List\n");
        printf("2. Create Second Linked List\n");
        printf("3. Display First Linked List\n");
        printf("4. Display Second Linked List\n");
        printf("5. Sort Linked List\n");
        printf("6. Reverse Linked List\n");
        printf("7. Concatenate Two Linked Lists\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    insert(&head1, value);
                }
                break;

            case 2:
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    insert(&head2, value);
                }
                break;

            case 3:
                printf("First Linked List: ");
                display(head1);
                break;

            case 4:
                printf("Second Linked List: ");
                display(head2);
                break;

            case 5:
                sort();
                display(head1);
                break;

            case 6:
                reverse();
                display(head1);
                break;

            case 7:
                concatenate();
                display(head1);
                break;

            case 8:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
