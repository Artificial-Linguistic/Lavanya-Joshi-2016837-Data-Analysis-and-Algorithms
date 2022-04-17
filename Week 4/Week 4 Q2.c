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

void swap(int *a,int *b,int *s)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    (*s)++;

    return;
}

int par(int arr[],int low,int high,int *c,int *s)
{
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j)
    {
        while(arr[i]<=pivot && i<j)
        {
            (*c)++;
            i++;
        }

        while(arr[j]>pivot)
        {
            (*c)++;
            j--;
        }

        if(i<j)
        {
            swap(&arr[i],&arr[j],s);
        }
    }
    swap(&arr[low],&arr[j],s);
    return j;
}

void q_sort(int arr[],int low,int high,int *c,int *s)
{
    if(low<high)
    {
        int j=par(arr,low,high,c,s);
        q_sort(arr,low,j-1,c,s);
        q_sort(arr,j+1,high,c,s);
    }
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

        int arr[n],swaps=0,comparision=0;
        input(arr,n);
        q_sort(arr,0,n-1,&comparision,&swaps);

        printf("Sorted Array: ");
        print(arr,n);
        printf("\nComparisions=%d\nSwaps=%d",comparision,swaps);
        printf("\n");
    }

    return 0;
}
