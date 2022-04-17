#include<stdio.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
}

void binary_search(int arr[],int n)
{
    int low=0,high=n-1,key,comparisons=0;

    printf("Enter the Search Key: ");
    scanf("%d",&key);

    while(low<=high)
    {
        int mid=(low+high)/2;
        comparisons++;

        if(arr[mid]==key)
        {
            printf("Present, %d",comparisons);
            return;
        }

        else if(key>arr[mid])
            low=mid+1;
        else
            high=mid-1;
    }

    printf("Not Present, %d",comparisons);
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
        binary_search(arr,n);
        printf("\n");
    }

    return 0;
}
