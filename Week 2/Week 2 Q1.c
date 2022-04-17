#include<stdio.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
}

int binary_search(int arr[],int l,int r,int key)
{
    if(l>r)
        return -1;

    int mid=(l+r)/2;

    if(arr[mid]==key)
    {
        int count;

        while(l<=mid)
        {
            if(arr[l]==key)
                count++;
            l++;
        }

        while(arr[r]==key&&r>mid)
        {
            if(arr[r]==key)
                count++;
            r--;
        }

        printf("%d - %d",key,count);

        return 1;
    }

    else if(arr[mid]>key)
        return binary_search(arr,l,mid-1,key);

    return binary_search(arr,mid+1,r,key);
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

        printf("Enter the Search Key: ");
        scanf("%d",&key);

        int res=binary_search(arr,0,n-1,key);

        if(res==-1)
            printf("Key not present");

        printf("\n");
    }

    return 0;
}
