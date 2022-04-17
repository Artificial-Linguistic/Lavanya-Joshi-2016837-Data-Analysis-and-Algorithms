#include<stdio.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
}

int sum_test(int arr[],int n)
{
    for(int i=n-1;i>=0;i--)
    {
        int j=0;
        int k=i-1;

        while(j<k)
        {
            if(arr[i]==arr[j]+arr[k])
            {
                printf("%d,%d,%d",j+1,k+1,i+1);
                return 1;
            }

            else if(arr[i]>arr[j]+arr[k])
                j+=1;

            else
                k-=1;
        }
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

        int res=sum_test(arr,n);

        if(res==-1)
            printf("No Sequence Found");

        printf("\n");
    }

    return 0;
}
