#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node *next;
} Stack;

Stack *top = NULL;

void push(int value) {
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    temp->data = value;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("\nUnderflow - Stack is Empty");
        return 0;
    } else {
        int val = top->data;
        Stack *temp = top;
        top = top->next;
        free(temp);
        return val;
    }
}

int evaluatePostfix(char postfix[]) {
    top = NULL;
    int i, num1, num2, res;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            num2 = pop();
            num1 = pop();
            switch (postfix[i]) {
                case '+': res = num1 + num2; break;
                case '-': res = num1 - num2; break;
                case '*': res = num1 * num2; break;
                case '/': res = num1 / num2; break;
            }
            push(res);
        }
    }
    return pop();
}

int evaluatePrefix(char prefix[]) {
    top = NULL;
    int i, num1, num2, res;
    int len = strlen(prefix);
    for (i = len - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(prefix[i] - '0');
        } else {
            num1 = pop();
            num2 = pop();
            switch (prefix[i]) {
                case '+': res = num1 + num2; break;
                case '-': res = num1 - num2; break;
                case '*': res = num1 * num2; break;
                case '/': res = num1 / num2; break;
            }
            push(res);
        }
    }
    return pop();
}

int main() {
    int choice;
    char expression[50];
    int result;

    printf("1. Evaluate Postfix Expression\n");
    printf("2. Evaluate Prefix Expression\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the Postfix Expression: ");
            scanf("%s", expression);
            result = evaluatePostfix(expression);
            printf("Result of Postfix Expression: %d\n", result);
            break;

        case 2:
            printf("Enter the Prefix Expression: ");
            scanf("%s", expression);
            result = evaluatePrefix(expression);
            printf("Result of Prefix Expression: %d\n", result);
            break;

        default:
            printf("Invalid Choice\n");
    }

    return 0;
}
