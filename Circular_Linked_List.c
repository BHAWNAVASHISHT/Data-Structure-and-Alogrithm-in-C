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
        temp->next = *start;
    } else {
        Node *ptr = *start;
        while (ptr->next != *start)
            ptr = ptr->next;
        ptr->next = temp;
        temp->next = *start;
    }
}

void addatbeg(int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    if (start == NULL) {
        start = temp;
        temp->next = start;
    } else {
        Node *ptr = start;
        while (ptr->next != start)
            ptr = ptr->next;
        temp->next = start;
        ptr->next = temp;
        start = temp;
    }
}

void addatpos(int value, int pos) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    if (pos == 1) {
        addatbeg(value);
        return;
    }
    Node *ptr = start;
    for (int i = 1; i < pos - 1 && ptr->next != start; i++)
        ptr = ptr->next;
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
    Node *ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    Node *temp = start;
    start = start->next;
    ptr->next = start;
    free(temp);
}

void delatend() {
    if (start == NULL)
        return;
    Node *ptr = start, *prev = NULL;
    while (ptr->next != start) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = start;
    free(ptr);
}

void delatpos(int pos) {
    if (start == NULL)
        return;
    if (pos == 1) {
        delatbeg();
        return;
    }
    Node *ptr = start, *prev = NULL;
    for (int i = 1; i < pos && ptr->next != start; i++) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
}

void display(Node *start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *ptr = start;
    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("(Back to start)\n");
}

void search(int value) {
    Node *ptr = start;
    int pos = 1;
    do {
        if (ptr->data == value) {
            printf("Element %d found at position %d\n", value, pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    } while (ptr != start);
    printf("Element not found\n");
}

void reverse() {
    if (start == NULL || start->next == start)
        return;
    Node *prev = NULL, *current = start, *next = NULL;
    Node *last = start;
    do {
        last = last->next;
    } while (last->next != start);

    Node *first = start;
    
    
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != start);

   
    first->next = prev;  
    start = prev;        
}

void sort() {
    if (start == NULL)
        return;
    Node *ptr1, *ptr2;
    int temp;
    for (ptr1 = start; ptr1->next != start; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != start; ptr2 = ptr2->next) {
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
        while (ptr->next != start)
            ptr = ptr->next;
        ptr->next = start2;
        ptr = start2;
        while (ptr->next != start2)
            ptr = ptr->next;
        ptr->next = start;
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
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Add at beginning\n2. Add at end\n3. Add at position\n4. Add before\n5. Add after\n6. Delete at beginning\n7. Delete at end\n8. Delete at position\n9. Display\n10. Search\n11. Reverse\n12. Sort\n13. Merge\n14. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 14) break;
        switch (choice) {
            case 1: scanf("%d", &value); addatbeg(value); break;
            case 2: scanf("%d", &value); addatend(&start, value); break;
            case 3: scanf("%d %d", &value, &pos); addatpos(value, pos); break;
            case 4: scanf("%d %d", &value, &pos); addbefore(value, pos); break;
            case 5: scanf("%d %d", &value, &pos); addafter(value, pos); break;
            case 6: delatbeg(); break;
            case 7: delatend(); break;
            case 8: scanf("%d", &pos); delatpos(pos); break;
            case 9: display(start); break;
            case 10: scanf("%d", &value); search(value); break;
            case 11: reverse(); break;
            case 12: sort(); break;
            case 13: merge(); break;
        }
    }
    return 0;
}
