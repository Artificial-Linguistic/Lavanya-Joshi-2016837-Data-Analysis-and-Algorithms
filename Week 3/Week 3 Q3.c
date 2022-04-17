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

void check_duplicates(int arr[],int n)
{
    q_sort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[i+1])
        {
            printf("YES");
            return;
        }
    }

    printf("NO");
    return;
}

int main()
{
    int t;

    printf("Enter Number of Test Cases: ");
    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        int n;
        printf("\nEnter Number of Elements: ");
        scanf("%d",&n);

        int arr[n];
        input(arr,n);
        check_duplicates(arr,n);
        printf("\n");
    }

    return 0;
}
