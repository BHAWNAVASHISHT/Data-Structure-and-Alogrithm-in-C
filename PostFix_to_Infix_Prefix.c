#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

struct Node* stack[100];
int top = -1;

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    return stack[top--];
}

struct Node* buildExpressionTree(char postfix[]) {
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isspace(ch)) continue;

        struct Node* newNode = createNode(ch);

        if (isOperator(ch)) {
            newNode->right = pop();
            newNode->left = pop();
        }
        push(newNode);
    }
    return pop();
}

void inorder(struct Node* root) {
    if (root != NULL) {
        if (isOperator(root->data)) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (isOperator(root->data)) printf(")");
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    char postfix[100];

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strcspn(postfix, "\n")] = '\0';  // remove newline

    struct Node* root = buildExpressionTree(postfix);

    printf("Inorder (infix): ");
    inorder(root);
    printf("\n");

    printf("Preorder (prefix): ");
    preorder(root);
    printf("\n");

    printf("Postorder (postfix): ");
    postorder(root);
    printf("\n");

    return 0;
}
