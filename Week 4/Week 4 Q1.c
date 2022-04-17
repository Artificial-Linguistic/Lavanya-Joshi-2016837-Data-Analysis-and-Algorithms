#include<stdio.h>

void input(int arr[],int n)
{
    printf("Enter Data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    return;
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return;
}

int merge(int arr[],int left,int mid,int right,int *c)
{
    int i,j,k,inversion=0;;
    int n1=mid-left+1;
    int n2=right-mid;
    int l[n1],r[n2];

    for(i=0;i<n1;i++)
        l[i]=arr[left+i];
    for(j=0;j<n2;j++)
        r[j]=arr[mid+1+j];

    i=j=0;
    k=left;

    while(i<n1&&j<n2)
    {
        (*c)++;
        if(l[i]<=r[j])
        {
            arr[k]=l[i];
            i++;
        }
        else
        {
            arr[k]=r[j];
            j++;
        }
        k++;
        inversion+=(mid-i);
    }

    while(i<n1)
    {
        arr[k]=l[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k]=r[j];
        j++;
        k++;
    }
}

int merge_sort(int arr[],int left,int right,int *c)
{
    int inversion=0;

    if(left<right)
    {
        int mid=(left+right)/2;

        inversion+=merge_sort(arr,left,mid,c);
        inversion+=merge_sort(arr,mid+1,right,c);
        inversion+=merge(arr,left,mid,right,c);
    }

    return inversion;
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

        int arr[n],comparisons=0;
        input(arr,n);
        int inversion=merge_sort(arr,0,n-1,&comparisons);

        printf("Sorted Array: ");
        print(arr,n);
        printf("\nComparisons=%d\nInversions=%d",comparisons,inversion);
        printf("\n");
    }

    return 0;
}
