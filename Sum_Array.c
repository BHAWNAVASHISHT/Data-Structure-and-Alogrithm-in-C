#include <stdio.h>
#include <stdio.h>
int sumarr(int arr[],int size)
{
    int i,sum=0;
    for(i=0;i<size;i++)
    {
        sum+=arr[i];
    } 
    return sum; 
}
int main()
{
    int searched;
    int ar[100];
    printf("ENTER THE NO. OF  ELEMENTS IN THE ARRAY:\n");
    int size;
    scanf("%d",&size);
    printf("ENTER THE ELEMENTS OF THE ARRAY:\n");
    for (int i=0;i<size;i++)
    {
        scanf("%d",&ar[i]);
    }
    int result=sumarr(ar,size);
        printf("SUM ARRAY ELEMENT IS,%d",result);
    return 0;
}
