//FloydWarshallAlgorithm
#include<iostream>
using namespace std;
int dist[1001][1001];
int main()
{
    int i, j, k, n, m, u, v, wt;
    for(i=0;i<1001;i++)
    {
        for(j=0;j<1001;j++)
        {
            if(i==j)
            dist[i][j]=0;
            else
            dist[i][j]=1001;
        }
    }
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>wt;
        dist[u][v]=wt;
        dist[v][u]=wt;
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if((dist[i][k]!=1001)&&(dist[k][j]!=1001)&&(dist[i][j]>(dist[i][k]+dist[k][j])))
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(dist[i][j]!=1001)
            cout<<dist[i][j]<<" ";
            else
            cout<<"I ";
        }
        cout<<endl;
    }
    return 0;
}