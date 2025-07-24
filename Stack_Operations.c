#include<stdio.h>
#define MAX 10
void stack_static()
{
    void push(int stack[],int *top,int value)
    {
        if(*top == MAX-1)
        {
            printf("\nOverflow-Stack is Empty");
        }
        else
        {
            *top = *top + 1;
            stack[*top] = value;
        }
    }
    int pop(int stack[],int *top)
    {
        if(*top == -1)
        {
            printf("\nUnderflow-Stack is Empty");
            return 0;
        }
        else
        {
            int val = stack[*top];
            *top = *top -1;
            return val;
        }
    }
    int isempty(int top)
    {
        if(top == -1)
            return 1;
        else
            return 0;
    }
    void display(int stack[],int top)
    {
        if(top == -1)
            printf("\nStack is Empty");
        else
        {
            printf("\nStack is ");
            for(int i = top; i>= 0; i--)
            {
                printf("\n%d",stack[i]);
            }
        }
    }
    int main()
    {
        int stack[MAX], top=-1;
        int ch,num;
        do
        {
            printf("\nPress 1 - Push");
            printf("\nPress 2 - Pop");
            printf("\nPress 3- Display");
            printf("\nPress 4 - Exit");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                printf("\nEnter the number to be inserted : ");
                scanf("%d",&num);
                push(stack,&top,num);
                break;
                case 2:
                num = pop(stack,&top);
                printf("\nDeleted number is %d",num);
                break;
                case 3:
                display(stack,top);
                
            }
    
        }while(ch!=4);
    }
}
void stack_dynamic()
{
    #include<stdio.h>
    #include<stdlib.h>
    
    typedef struct Node
    {
        int data;
        struct Node *next;
    }Stack;
    
    Stack *top;
    void push(int value)
    {
        Stack *temp;
        temp = (Stack*) malloc(sizeof(Stack));
        temp->data = value;
        temp->next = top;
        top = temp;
    }
    int pop()
    {
        if(top == NULL)
        {
            printf("\nUnderflow-Stack is Empty");
            return 0;
        }
        else
        {
            int val = top->data;
            Stack *temp = top;
            top = top->next;
            free(temp);
            return val;
        }
    }
    int isempty()
    {
        if(top == NULL)
            return 1;
        else
            return 0;
    }
    void display()
    {
        if(top == NULL)
            printf("\nStack is Empty");
        else
        {
            printf("\nStack is ");
            for(Stack *p = top; p!= NULL; p=p->next)
            {
                printf("\n%d",p->data);
            }
        }
    }
    int main()
    {
        top = NULL;
        int ch,num;
        do
        {
            printf("\nPress 1 - Push");
            printf("\nPress 2 - Pop");
            printf("\nPress 3- Display");
            printf("\nPress 4 - Exit");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                printf("\nEnter the number to be inserted : ");
                scanf("%d",&num);
                push(num);
                break;
                case 2:
                num = pop();
                printf("\nDeleted number is %d",num);
                break;
                case 3:
                display();
                
            }
    
        }while(ch!=4);
    }
}
int main()
{
    printf("ENTER 1 FOR STATIC IMPLEMENTATION OF STACK1");
    printf("ENTER 1 FOR STATIC IMPLEMENTATION OF STACK1");
    int method;
    printf("ENTER YOUR CHOICE");
    scanf("%d",&method);
}
