#include<stdio.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
}

void linear_search(int arr[],int s,int e,int key,int comparisons)
{
    for (int i=s;i<e;i++)
    {
        comparisons++;
        if(arr[i]==key)
        {
            printf("Present, %d",comparisons);
            return;
        }
    }

    printf("Not Present, %d",comparisons);
    return;
}

void binary_search(int arr[],int low,int high,int comparisons,int key)
{
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

void expo_search(int arr[],int n)
{
    int comparisons=0,key,i;

    printf("Enter the Search Key: ");
    scanf("%d",&key);

    comparisons++;
    if(arr[0]==key)
    {
        printf("Present, %d",comparisons);
        return;
    }
    for(i=2;i<n;i=i*2)
    {
        comparisons++;
        if(arr[i]==key)
        {
            printf("Present, %d",comparisons);
            return;
        }

        else if(arr[i]>key)
        {
            linear_search(arr,i/2,i,key,comparisons);
            return;
        }
    }
    binary_search(arr,(i/2)+1,n-1,comparisons,key);
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
        expo_search(arr,n);
        printf("\n");
    }

    return 0;
}
