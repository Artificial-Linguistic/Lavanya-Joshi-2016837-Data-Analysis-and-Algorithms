#include<stdio.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
}

int count_diff(int arr[],int n,int k)
{
    int count=0;

    for(int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if(arr[i]-arr[j]==k||arr[j]-arr[i]==k)
                count++;
        }
    }

    return count;
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

        printf("Enter the Difference Key: ");
        scanf("%d",&key);

        int res=count_diff(arr,n,key);

        printf("Difference Count: %d",res);
        printf("\n");
    }

    return 0;
}
