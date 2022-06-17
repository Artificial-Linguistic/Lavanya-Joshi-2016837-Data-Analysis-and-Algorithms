#include<bits/stdc++.h>
using namespace std;

int minimum_comp(int arr[],int n)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
      pq.push(arr[i]);

    int res=0;
    while(pq.size()>=2)
    {
        int temp=pq.top();
        pq.pop();
        temp+=pq.top();
        pq.pop();

        res+=temp;
        pq.push(temp);
    }

    return res;


}
int main()
{
    int n;
    cout<<"Enter Size of the Array: ";
    cin>>n;
    cout<<"Enter the Elements: ";
    int arr[n];

    for (int i=0;i<n;i++)
       cin>>arr[i];

    cout<<"\nMinimum Computation: "<<minimum_comp(arr,n)<<endl;

    return 0;
}
