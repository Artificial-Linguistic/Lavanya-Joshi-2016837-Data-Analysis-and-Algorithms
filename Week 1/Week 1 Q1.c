#include<stdio.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
}

void search_num(int arr[],int n)
{
    int key;
    printf("Enter the Search Key: ");
    scanf("%d",&key);

    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            printf("Present, %d\n",i+1);
            return;
        }
    }

    printf("Not Present, %d\n",n);
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
        search_num(arr,n);
    }

    return 0;
}
