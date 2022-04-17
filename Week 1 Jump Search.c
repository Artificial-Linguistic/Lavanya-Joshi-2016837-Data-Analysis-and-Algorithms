#include<stdio.h>
#include<math.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
}

void jump_search(int arr[],int n)
{
    int comparisions=0,key,prev=0,step=sqrt(n);

    printf("Enter the Search Key: ");
    scanf("%d",&key);

    while(arr[step-1]<key)
    {
        comparisions++;
        prev=step;
        step+=sqrt(n);

        if(step>n-1)
            step=n;
    }

    for(int i=prev;i<step;i++)
    {
        comparisions++;
        if(key==arr[i])
        {
            printf("Present, %d",comparisions);
            return;
        }
    }

    printf("Not Present, %d",comparisions);
    return;
}

int main()
{
    int t;

    printf("Enter Total Cases: ");
    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        int n;
        printf("\nEnter Number of Elements: ");
        scanf("%d",&n);

        int arr[n];
        input(arr,n);
        jump_search(arr,n);
        printf("\n");
    }

    return 0;
}
