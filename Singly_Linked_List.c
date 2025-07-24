/*1.WAP to implement a Singly Linked List.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *start = NULL;
Node *start2 = NULL;

void addatend(Node **start, int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    
    if (*start == NULL) {
        *start = temp;
    } else {
        Node *ptr = *start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void addatbeg(int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = start;
    start = temp;
}

void addatpos(int value, int pos) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if (pos == 1) {
        temp->next = start;
        start = temp;
        return;
    }

    Node *ptr = start;
    for (int i = 1; ptr != NULL && i < pos - 1; i++)
        ptr = ptr->next;

    if (ptr == NULL) {
        free(temp);
        return;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

void addbefore(int value, int pos) {
    addatpos(value, pos - 1);
}

void addafter(int value, int pos) {
    addatpos(value, pos + 1);
}

void delatbeg() {
    if (start == NULL)
        return;
    Node *temp = start;
    start = start->next;
    free(temp);
}

void delatend() {
    if (start == NULL)
        return;
    if (start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }
    Node *ptr = start, *prev = NULL;
    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    free(ptr);
}

void delatpos(int pos) {
    if (start == NULL)
        return;
    Node *temp = start;
    if (pos == 1) {
        start = start->next;
        free(temp);
        return;
    }

    Node *prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void display(Node *start) {
    Node *ptr = start;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void search(int value) {
    Node *ptr = start;
    int pos = 1;
    while (ptr != NULL) {
        if (ptr->data == value) {
            printf("Element %d found at position %d\n", value, pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    printf("Element not found\n");
}

void reverse() {
    Node *prev = NULL, *current = start, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}

void sort() {
    if (start == NULL)
        return;
    Node *ptr1, *ptr2;
    int temp;
    for (ptr1 = start; ptr1->next != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if (ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }
}

void merge() {
    int n, value;
    printf("Enter the number of nodes for the second list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        addatend(&start2, value);
    }

    if (start == NULL) {
        start = start2;
    } else {
        Node *ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = start2;
    }
    printf("Lists merged successfully!\n");
}

int main() {
    int choice, value, pos, n;

    printf("Enter the number of initial nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        addatend(&start, value);
    }

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Add at beginning\n");
        printf("2. Add at end\n");
        printf("3. Add at position\n");
        printf("4. Add before position\n");
        printf("5. Add after position\n");
        printf("6. Delete at beginning\n");
        printf("7. Delete at end\n");
        printf("8. Delete at position\n");
        printf("9. Display\n");
        printf("10. Search\n");
        printf("11. Reverse\n");
        printf("12. Sort\n");
        printf("13. Merge\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add at beginning: ");
                scanf("%d", &value);
                addatbeg(value);
                break;
            case 2:
                printf("Enter value to add at end: ");
                scanf("%d", &value);
                addatend(&start, value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                addatpos(value, pos);
                break;
            case 4:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                addbefore(value, pos);
                break;
            case 5:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                addafter(value, pos);
                break;
            case 6:
                delatbeg();
                break;
            case 7:
                delatend();
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delatpos(pos);
                break;
            case 9:
                display(start);
                break;
            case 10:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 11:
                reverse();
                printf("List reversed\n");
                break;
            case 12:
                sort();
                printf("List sorted\n");
                break;
            case 13:
                merge();
                break;
            case 14:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
