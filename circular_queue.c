#include <stdio.h>
#define MAX 5

int cqueue[MAX];
int front = -1, rear = -1;

void insert(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Circular Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        cqueue[rear] = value;
        printf("Inserted %d into circular queue\n", value);
    }
}

void delete() {
    if (front == -1) {
        printf("Circular Queue Underflow! Queue is empty\n");
    } else {
        printf("Deleted %d from circular queue\n", cqueue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Circular Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", cqueue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
