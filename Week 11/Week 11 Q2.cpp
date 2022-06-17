#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,amt;
    cout<<"Enter the Available Number of Coins: ";
    cin>>n;

    int i,j,a[n];
    cout<<"Enter Value of Each Coin: ";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the Value Required: ";
    cin>>amt;

    int ans[amt+1];
    for(i=1;i<=amt;i++)
        ans[i]=0;
    ans[0]=1;

    for(j=0;j<n;j++)
    {
        for(i=1;i<=amt;i++)
        {
            if(a[j]<=i)
            ans[i]+=(ans[i-a[j]]);
        }
    }

    cout<<"\nTotal Number of Ways: "<<ans[amt]<<endl;

    return 0;
}
