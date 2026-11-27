#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertBegin(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning\n", value);
}

void insertMiddle(int value, int pos) {
    if (pos <= 1 || head == NULL) {
        insertBegin(value);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", value, pos);
}

void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at end\n", value);
}

void deleteBegin() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Deleted %d from beginning\n", head->data);
    head = head->next;
    free(temp);
}

void deleteMiddle(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos <= 1) {
        deleteBegin();
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    prev->next = temp->next;
    printf("Deleted %d from position %d\n", temp->data, pos);
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted %d from end\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted %d from end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at Middle\n3. Insert at End\n");
        printf("4. Delete from Beginning\n5. Delete from Middle\n6. Delete from End\n");
        printf("7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBegin(value);
                break;
            case 2:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertMiddle(value, pos);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 4:
                deleteBegin();
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteMiddle(pos);
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                display();
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
