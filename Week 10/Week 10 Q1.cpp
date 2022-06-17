#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Number of Activities: ";
    cin>>n;

    int i,s[n],f[n];

    cout<<"Enter Starting Time for All Activities: ";
    for(i=0;i<n;i++)
        cin>>s[i];
    cout<<"Enter Finishing Time for All Activities: ";
    for(i=0;i<n;i++)
        cin>>f[i];

    vector<vector<int>> a;
    vector<int> act;

    for(i=0;i<n;i++)
        a.push_back({f[i],s[i],i+1});
    sort(a.begin(),a.end());

    int e=INT_MIN,c=0;
    for(i=0;i<n;i++)
    {
        if(a[i][1]>=e)
        {
            e=a[i][0];
            c++;
            act.push_back(a[i][2]);
        }
    }

    cout<<"\nNo. of Non-Conflicting Activities: "<<c<<endl;
    cout<<"List of Selected Activities: ";
    for(i=0;i<act.size();i++)
        cout<<act[i]<<",";
    cout<<endl;

    return 0;
}
