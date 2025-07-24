#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Deque;

Deque *front = NULL, *rear = NULL;

void insert_front_static(int deque[], int *front, int *rear, int value) {
    if ((*front == 0 && *rear == MAX - 1) || (*front == *rear + 1)) {
        printf("\nOverflow - De-Queue is Full");
    } else {
        if (*front == -1) {
            *front = *rear = 0;
        } else if (*front == 0) {
            *front = MAX - 1;
        } else {
            (*front)--;
        }
        deque[*front] = value;
    }
}

void insert_rear_static(int deque[], int *front, int *rear, int value) {
    if ((*front == 0 && *rear == MAX - 1) || (*front == *rear + 1)) {
        printf("\nOverflow - De-Queue is Full");
    } else {
        if (*front == -1) {
            *front = *rear = 0;
        } else if (*rear == MAX - 1) {
            *rear = 0;
        } else {
            (*rear)++;
        }
        deque[*rear] = value;
    }
}

int delete_front_static(int deque[], int *front, int *rear) {
    if (*front == -1) {
        printf("\nUnderflow - De-Queue is Empty");
        return 0;
    }
    int val = deque[*front];
    if (*front == *rear) {
        *front = *rear = -1;
    } else if (*front == MAX - 1) {
        *front = 0;
    } else {
        (*front)++;
    }
    return val;
}

int delete_rear_static(int deque[], int *front, int *rear) {
    if (*rear == -1) {
        printf("\nUnderflow - De-Queue is Empty");
        return 0;
    }
    int val = deque[*rear];
    if (*front == *rear) {
        *front = *rear = -1;
    } else if (*rear == 0) {
        *rear = MAX - 1;
    } else {
        (*rear)--;
    }
    return val;
}

void display_static(int deque[], int front, int rear) {
    if (front == -1) {
        printf("\nDe-Queue is Empty");
    } else {
        printf("\nDe-Queue is:\n");
        int i = front;
        while (1) {
            printf("%d\n", deque[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
    }
}

void insert_front_dynamic(int value) {
    Deque *temp = (Deque *)malloc(sizeof(Deque));
    temp->data = value;
    temp->prev = NULL;
    temp->next = front;
    if (front == NULL) {
        front = rear = temp;
    } else {
        front->prev = temp;
        front = temp;
    }
}

void insert_rear_dynamic(int value) {
    Deque *temp = (Deque *)malloc(sizeof(Deque));
    temp->data = value;
    temp->next = NULL;
    temp->prev = rear;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

int delete_front_dynamic() {
    if (front == NULL) {
        printf("\nUnderflow - De-Queue is Empty");
        return 0;
    }
    int val = front->data;
    Deque *temp = front;
    front = front->next;
    if (front != NULL)
        front->prev = NULL;
    else
        rear = NULL;
    free(temp);
    return val;
}

int delete_rear_dynamic() {
    if (rear == NULL) {
        printf("\nUnderflow - De-Queue is Empty");
        return 0;
    }
    int val = rear->data;
    Deque *temp = rear;
    rear = rear->prev;
    if (rear != NULL)
        rear->next = NULL;
    else
        front = NULL;
    free(temp);
    return val;
}

void display_dynamic() {
    if (front == NULL) {
        printf("\nDe-Queue is Empty");
    } else {
        printf("\nDe-Queue is:\n");
        Deque *p = front;
        while (p != NULL) {
            printf("%d\n", p->data);
            p = p->next;
        }
    }
}

int main() {
    int method;
    printf("ENTER 1 FOR STATIC IMPLEMENTATION OF DE-QUEUE\n");
    printf("ENTER 2 FOR DYNAMIC IMPLEMENTATION OF DE-QUEUE\n");
    printf("ENTER YOUR CHOICE\n");
    scanf("%d", &method);

    switch (method) {
    case 1: {
        int deque[MAX], front = -1, rear = -1, choice, num;
        do {
            printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                printf("Enter number to insert at front: ");
                scanf("%d", &num);
                insert_front_static(deque, &front, &rear, num);
                break;
            case 2:
                printf("Enter number to insert at rear: ");
                scanf("%d", &num);
                insert_rear_static(deque, &front, &rear, num);
                break;
            case 3:
                num = delete_front_static(deque, &front, &rear);
                printf("Deleted: %d\n", num);
                break;
            case 4:
                num = delete_rear_static(deque, &front, &rear);
                printf("Deleted: %d\n", num);
                break;
            case 5:
                display_static(deque, front, rear);
                break;
            }
        } while (choice != 6);
        break;
    }
    case 2: {
        int choice, num;
        do {
            printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                printf("Enter number to insert at front: ");
                scanf("%d", &num);
                insert_front_dynamic(num);
                break;
            case 2:
                printf("Enter number to insert at rear: ");
                scanf("%d", &num);
                insert_rear_dynamic(num);
                break;
            case 3:
                num = delete_front_dynamic();
                printf("Deleted: %d\n", num);
                break;
            case 4:
                num = delete_rear_dynamic();
                printf("Deleted: %d\n", num);
                break;
            case 5:
                display_dynamic();
                break;
            }
        } while (choice != 6);
        break;
    }
    default:
        printf("Invalid Choice\n");
    }
    return 0;
}
