#include<stdio.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
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

int sum_test(int arr[],int n)
{
    int i=0,j=n-1,key;

    printf("Enter Key: ");
    scanf("%d",&key);

    while(j>i)
    {
        if(arr[i]+arr[j]==key)
        {
            printf("%d,%d",arr[i],arr[j]);
            return 1;
        }

        else if(key>arr[i]+arr[j])
            i++;
        else
            j--;
    }

    return -1;
}

int main()
{
    int t;
    printf("Enter Number of Test Cases: ");
    scanf("%d",&t);

    for (int i=0;i<t;i++)
    {
        int n;
        printf("\nEnter Number of Elements: ");
        scanf("%d",&n);

        int arr[n];
        input(arr,n);
        q_sort(arr,0,n-1);
        int res=sum_test(arr,n);

        if(res==-1)
            printf("No Such Element Exists");

        printf("\n");
    }

    return 0;
}
