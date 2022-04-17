#include<stdio.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return;
}

void in_sort(int arr[],int n)
{
    int shifts=0,comparisons=0;

    for(int i=1;i<n;i++)
    {
        int t=arr[i];
        int j=i-1;

        while(j>=0&&arr[j]>t)
        {
            comparisons++;
            arr[j+1]=arr[j];
            j--;
            shifts++;
        }
        arr[j+1]=t;
        shifts++;
    }

    printf("\nSorted Array: ");
    fflush(stdin);
    print(arr,n);
    printf("\nComparisons=%d\nShifts=%d",comparisons,shifts);

    return;
}

int main()
{
    int t;

    printf("Enter Number of Test Cases: ");
    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        int n,key;
        printf("\nEnter Number of Elements: ");
        scanf("%d",&n);

        int arr[n];
        input(arr,n);
        in_sort(arr,n);

        printf("\n");
    }

    return 0;
}
