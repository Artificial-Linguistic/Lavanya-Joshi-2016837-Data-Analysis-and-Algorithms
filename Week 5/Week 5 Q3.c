#include<stdio.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
}

int Intersection(int arr1[],int arr2[],int m,int n)
{
    int i=0,j=0,flag=0;

    while(i<m && j<n)
    {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]>arr2[j])
            j++;
        else
        {
            printf("%d ",arr2[j++]);
            i++;
            flag=1;
        }
    }

    return flag;
}

int main()
{
    int m,n,flag;

    printf("Enter Size of Array1: ");
    scanf("%d",&m);

    int arr1[m];
    printf("Array 1:\n");
    input(arr1,m);

    printf("\nEnter Size of Array2: ");
    scanf("%d",&n);

    int arr2[n];
    printf("Array 2:\n");
    input(arr2,n);
    printf("\n");
    flag=Intersection(arr1,arr2,m,n);

    if(flag!=1)
        printf("No Common Element Exists\n");

    return 0;
}
