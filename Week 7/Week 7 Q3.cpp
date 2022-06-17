#include <bits/stdc++.h>
using namespace std;

int shortest_weigt(int **graph,int ver,int u,int v,int k)
{
    if(k<=0)
        return INT_MAX;
    if(k==0&&u==v)
        return 0;
    if(k==1&&graph[u][v]!=INT_MAX)
        return graph[u][v];

    int res=INT_MAX;
    for(int i=0;i<ver;i++)
    {
        if(graph[u][i]!=0&&u!=i&&v!=i)
        {
            int recu=shortest_weigt(graph, ver, i, v, k - 1);
            if(recu!=INT_MAX)
                res=min(res, graph[u][i] + recu);
        }
    }
    return res;
}

int main()
{
    int ver,u,v,k,ans;

    cout<<"Enter Number of Vertices: ";
    cin>>ver;

    int **graph=(int**)malloc(ver*sizeof(int *));
    cout<<"Enter Adjacency Matrix: "<<endl;
    for(int i=0;i<ver;i++)
        graph[i]=(int*)malloc(sizeof(int)*ver);
    for(int i=0;i<ver;i++)
        for(int j=0;j<ver;j++)
            cin>>graph[i][j];

    cout<<"Enter Start and Destination Node: ";
    cin>>u>>v;
    cout<<"Enter Number of Edges between the Two Nodes: ";
    cin>>k;
    ans=shortest_weigt(graph,ver,u-1,v-1,k);
    cout<<"\nWeight of Shortest Path from ("<<u<<","<<v<<") with "<<k<<" Edges: "<<ans<<endl;

    return 0;
}
