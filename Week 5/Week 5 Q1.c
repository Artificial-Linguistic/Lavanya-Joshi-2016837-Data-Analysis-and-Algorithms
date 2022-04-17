#include<stdio.h>
#include<string.h>
#define RANGE 26

void input(char arr[],int n)
{
    printf("Enter Characters: ");
    for(int i=0;i<n;i++)
        scanf("%s",&arr[i]);

    return;
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d",arr[i]);
}

void count_duplicates(char arr[],int n)
{
    int count[RANGE]={0};

    for(int i=0;i<n;i++)
        ++count[(int)arr[i]-97];

    int pos=0,large=count[0];

    for(int i=1;i<RANGE;i++)
    {
        if(large<count[i])
        {
            large=count[i];
            pos=i;
        }
    }

    if(large==1)
        printf("No Duplicates Present");
    else
        printf("%c-%d",pos+97,count[pos]);
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

        char arr[n];
        input(arr,n);
        count_duplicates(arr,n);
        fflush(stdin);
        printf("\n");
    }

    return 0;
}
