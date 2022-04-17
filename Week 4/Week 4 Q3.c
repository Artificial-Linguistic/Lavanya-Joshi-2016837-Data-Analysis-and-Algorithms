#include<stdio.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
}

int remove_duplicates(int arr[],int n)
{
    if(n==0||n==1)
        return n;

    int temp[n],j=0;

    for(int i=0;i<n-1;i++)
    {
        if(arr[i]!=arr[i+1])
            temp[j++]=arr[i];
    }

    temp[j++]=arr[n-1];

    for(int i=0;i<j;i++)
        arr[i]=temp[i];

    return j;
}

void k_small(int arr[],int n)
{
    int key;

    printf("Enter Key: ");
    scanf("%d",&key);

    printf("%dth Largest Element: %d",key,arr[key-1]);
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

    return;
}

int par(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j)
    {
        while(arr[i]<=pivot && i<j)
        {
            i++;
        }

        while(arr[j]>pivot)
        {
            j--;
        }

        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void q_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int j=par(arr,low,high);
        q_sort(arr,low,j-1);
        q_sort(arr,j+1,high);
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

        int arr[n];
        input(arr,n);
        q_sort(arr,0,n-1);
        n=remove_duplicates(arr,n);
        k_small(arr,n);
        printf("\n");
    }

    return 0;
}
