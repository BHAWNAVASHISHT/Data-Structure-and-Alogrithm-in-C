/*WAP to search & display the location of an element specified by the user, in an array using
(i) Linear Search (ii) Binary Search technique.*/
#include <stdio.h>
void linearsearch(int arr[],int n,int num)
{
	int i;
	for (i=0;i<n;i++)
	{
		if(arr[i]==num)
		{
			printf("ELEMENT FOUND AT %d POSITION",i
            );
			return;
		}
	}
    printf("ELEMENT NOT FOUND");
}
void binarysearch(int arr[],int n,int num)
{
	int i;
    int mid;
    int ub,lb;
    lb=0;
    ub=n-1;
	while (lb<=ub)
	{
        mid=(lb+ub)/2;
		if(arr[mid]==num)
		{
			printf("ELEMENT FOUND AT %d POSITION",mid);
            return;
		}
        else if(arr[mid]>num)
        {
            ub=mid-1;
        }
        else 
        {
            lb=mid+1;
        }
	}
    printf("ELEMENT NOT FOUND");
}
int main()
{
    int i,ch;
    int arr[20];
    int n;
    printf("ENTER THE SIZE OF ARRAY:");
    scanf("%d",&n);
    arr[n];
    printf("ENTER THE ELEMENTS OF THE ARRAY:");
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("ENTER THE NUMBER TO BE SEARCHED IN THE ARRAY:");
    int num;
    scanf("%d",&num);
    printf("ENTER 1 TO SEARCHED USING LINEAR SEARCH!");
    printf("\nENTER 2 TO SEARCHED USING BINARY SEARCH!");
    printf("\nENTER THE SORTED ARRAY AS IN CASE OF BINARY SEARCH IT WOULD BE PRE-REQUISITE TO SEARCH");
    printf("\nENTER THE CHOICE:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            linearsearch(arr,n,num);
            break;
        }
        case 2:
        {
            binarysearch(arr,n,num);
            break;
        }
        default:
        {
            printf("INVALID CHOICE");
        } 
    }
    return 0;
}
