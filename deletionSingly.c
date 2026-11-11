#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Helper: Allocate a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Helper: Insert at end to populate the list for deletion tests
void insertEnd(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// 1. Delete at beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted!\n");
}

// 2. Delete at specified position (1-based index)
void deletePosition(int position) {
    if (head == NULL || position < 1) {
        printf("Invalid position or empty list!\n");
        return;
    }

    if (position == 1) {
        deleteBeginning();
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);

    printf("Node at position %d deleted successfully!\n", position);
}

// 3. Delete at end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted!\n");
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    printf("Last node deleted!\n");
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Free all remaining nodes before exit
void freeList() {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice, value, position;

    while (1) {
        printf("1. Add Node\n");
        printf("2. Delete at Beginning\n");
        printf("3. Delete at Specified Position\n");
        printf("4. Delete at End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 2:
                deleteBeginning();
                break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deletePosition(position);
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                freeList();
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}