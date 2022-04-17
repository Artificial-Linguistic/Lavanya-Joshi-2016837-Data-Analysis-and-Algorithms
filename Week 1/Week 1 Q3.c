#include<stdio.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
}

void linear_search(int arr[],int s,int e,int comparisions,int key)
{
    for (int i=s;i<e;i++)
    {
        comparisions++;
        if(arr[i]==key)
        {
            printf("Present, %d",comparisions);
            return;
        }
    }

    printf("Not Present, %d",comparisions);
    return;
}

void binary_search(int arr[],int low,int high,int comparisions,int key)
{
     while(low<=high)
    {
        int mid=(low+high)/2;
        comparisions++;

        if(arr[mid]==key)
        {
            printf("Present, %d",comparisions);
            return;
        }

        else if(key>arr[mid])
            low=mid+1;
        else
            high=mid-1;
    }

    printf("Not Present, %d",comparisions);
    return;
}

void expo_search(int arr[],int n)
{
    int comparisions=0,key,i;

    printf("Enter the Search Key: ");
    scanf("%d",&key);

    comparisions++;
    if(arr[0]==key)
    {
        printf("Present, %d",comparisions);
        return;
    }
    for(i=2;i<n;i=i*2)
    {
        comparisions++;
        if(arr[i]==key)
        {
            printf("Present, %d",comparisions);
            return;
        }

        else if(arr[i]>key)
        {
            linear_search(arr,i/2,i,comparisions,key);
            return;
        }
    }
    binary_search(arr,(i/2)+1,n-1,comparisions,key);
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
