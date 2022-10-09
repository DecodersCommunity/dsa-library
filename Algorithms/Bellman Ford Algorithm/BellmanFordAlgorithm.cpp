//BellmanFordAlgorithm
#include<iostream>
using namespace std;
struct edge
{
    int u;
    int v;
    int wt;
};
struct edge e[100001];
int dist[100001];
int main()
{
    int i, j, n, m, u, v, wt;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>wt;
        e[i].u=u;
        e[i].v=v;
        e[i].wt=wt;
    }
    for(i=0;i<100001;i++)
    dist[i]=100001;
    dist[1]=0;
    for(i=1;i<n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(dist[e[j].v]>(dist[e[j].u]+e[j].wt))
            dist[e[j].v]=dist[e[j].u]+e[j].wt;
        }
    }
    for(i=1;i<=n;i++)
    cout<<i<<" -> "<<dist[i]<<endl;
    return 0;
}