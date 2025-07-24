/*WAP to implement Polynomial addition operation using Linked list.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int coeff;
    int exp;
    struct Node *next;
}Poly;



Poly* addatend(Poly *start,int value,int power)
{
    Poly *temp;
    temp = (Poly*)malloc(sizeof(Poly));
    temp->coeff = value;
    temp->exp = power;
    temp->next = NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        Poly *ptr;
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
    return start;
}
void display(Poly *start)
{
    Poly *ptr;
    ptr = start;
    printf("\nPolynomial is : ");
    while(ptr != NULL)
    {
        printf(" %d x^%d +",ptr->coeff,ptr->exp);
        ptr = ptr->next;
    }
    printf("\n");
}

Poly* add(Poly *p,Poly *q)
{
    Poly *newstart=NULL;
    while( p!=NULL && q!=NULL)
    {
        if(p->exp > q->exp)
        {
            newstart = addatend(newstart,p->coeff,p->exp);
            p = p->next;
        }
        else if(q->exp > p->exp)
         {
               newstart = addatend(newstart,q->coeff,q->exp);
               q=q->next;
         }
         else{
            newstart = addatend(newstart, p->coeff+q->coeff, p->exp);
            p=p->next;
            q=q->next;
         }

    }
    while(p!=NULL)
    {
        newstart = addatend(newstart,p->coeff,p->exp);
        p = p->next;
    }
    while(q!=NULL)
    {
        newstart = addatend(newstart,q->coeff,q->exp);
        q = q->next;
    }
    return newstart;
}
int main()
{
    int n,m,i,num;
    Poly *start1,*start2,*result;
    start1 = start2 = NULL;
    printf("\nWhat is the degree of first polynomial : ");
    scanf("%d",&n);
    for(i =n; i>=0;i--)
    {
        printf("\nEnter the value for power %d : ",i);
        scanf("%d",&num);
        if(num != 0)
        start1 = addatend(start1,num,i);
    }
    printf("\nWhat is the degree of Polynomial 2 :");
    scanf("%d",&m);
    for(i =m; i>=0;i--)
    {
        printf("\nEnter the value for power %d : ",i);
        scanf("%d",&num);
        if(num != 0)
        start2 = addatend(start2,num,i);
    }
    printf("\nPolynomial 1 is ");
    display(start1);
    printf("Polynomial 2 is ");
    display(start2);
    result = add(start1,start2);
    printf("\nResult Polynomial is ");
    display(result);
    return 0;
}
