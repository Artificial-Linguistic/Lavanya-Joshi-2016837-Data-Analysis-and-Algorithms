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

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void select_sort(int arr[],int n)
{
    int comparisions=0,swaps=0,pos=0;

    for(int i=0;i<n-1;i++)
    {
        pos=i;

        for(int j=i+1;j<n;j++)
        {
            comparisions++;
            if(arr[pos]>arr[j])
                pos=j;
        }
        swap(&arr[pos],&arr[i]);
        swaps++;
    }

    print(arr,n);
    printf("\nComparisions=%d\nSwaps=%d",comparisions,swaps);

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
        select_sort(arr,n);

        printf("Sorted Array: ");
        printf("\n");
    }

    return 0;
}
