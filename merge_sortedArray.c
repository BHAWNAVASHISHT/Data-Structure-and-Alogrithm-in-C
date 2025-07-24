// 4. Write a program to merge two sorted arrays
#include <stdio.h>
void merge(int arr1[],int size1,int arr2[],int size2)
{
    int i=0,j=0,k=0;
    int size3=size1+size2;
    int arr3[size3];
    while(i<size1 && j<size2)
    {
        if (arr1[i]<arr2[j])
        {
            arr3[k++]=arr1[i++];
        }
        else
        {
            arr3[k++]=arr2[j++];
        }
    }
    while(i<size1)
    {
        arr3[k++]=arr1[i++];
    }
    while(j<size2)
    {
        arr3[k++]=arr2[j++];
    }
    printf("ARRAY AFTER MERGING IS:");
    for (i=0;i<size3;i++)
    {
        printf("%d  ",arr3[i]);
    }

}
int main()
{
    int i;
    int ar1[20];
    int ar2[20];
    int size1,size2;
    printf("ENTER THE NUMBER OF ELEMENTS IN ARRAY 1:");
    scanf("%d",&size1);
    printf("ENTER THE ELEMENTS OF THE ARRAY");
    for (i=0;i<size1;i++)
    {
        scanf("%d",&ar1[i]);
    }
    printf("ENTER THE NUMBER OF ELEMENTS IN ARRAY 2:");
    scanf("%d",&size2);
    printf("ENTER THE ELEMENTS OF THE ARRAY");
    for (i=0;i<size2;i++)
    {
        scanf("%d",&ar2[i]);
    }
    merge(ar1,size1,ar2,size2);
    return 0;
}
