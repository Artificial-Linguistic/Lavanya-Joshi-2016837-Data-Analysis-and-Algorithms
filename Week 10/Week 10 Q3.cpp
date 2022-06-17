#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Size of the Array: ";
    cin>>n;

    int i,a[n],c,j;
    cout<<"Enter the Elements: ";
    for(i=0;i<n;i++)
        cin>>a[i];

    bool f=0;
    sort(a,a+n);

    for(i=0;i<n;i++)
    {
        c=1;
        j=i+1;

        while(j<n && a[j++]==a[i])
            c++;
        if(c>n/2)
        {
            cout<<"\nYes\n";
            f=1;
            break;
        }
        i=j-1;
    }

    if(f==0)
        cout<<"\nNo\n";
    if(n%2!=0)
        cout<<"Median: "<<a[n/2]<<endl;
    else
        cout<<"Median: "<<((float)a[n/2]+a[n/2-1])/2<<endl;

    return 0;
}
