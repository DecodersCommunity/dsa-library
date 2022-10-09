//Contributed By- Shashank Rai(shashank.rai00331@gmail.com)

// In this section we will be adding the node class of the graph data structure 

// We can use all the functions in the class to perform operations on graphs .



#include <iostream>
#include<queue>
using namespace std;

void printBFS(int **edges, int n, int sv)
{
    queue<int> pendingnodes;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    pendingnodes.push(sv);
    visited[sv] = true;
    
    while (!pendingnodes.empty())
    {
        int currentindex = pendingnodes.front();
        pendingnodes.pop();
        cout << currentindex << endl;
        for(int i =0; i<n; i++)
        {
            if(i == currentindex)
            {
                continue;
            }
            if(edges[currentindex][i] == 1 && !visited[i])
            {
                pendingnodes.push(i);
                visited[i] = true;
            }
        }

    }
    delete[] visited;
}


void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

int main()
{

    int n;
    int e;
    cin >> n >> e;
    int **edges = new int *[n];

    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    printDFS(edges, n, 0, visited);
    printBFS(edges, n, 0);
}

