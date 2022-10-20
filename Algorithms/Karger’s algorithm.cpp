nitin kumar<200104042@hbtu.ac.in>

                    Karger’s algorithm for Minimum Cut 
                    

#include <iostream>
#include <time.h>

struct Edge
{
	int src, dest;
};
struct Graph
{

	int V, E;

	Edge* edge;
};
struct subset
{
	int parent;
	int rank;
};

int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);
int kargerMinCut(struct Graph* graph)
{
	// Get data of given graph
	int V = graph->V, E = graph->E;
	Edge *edge = graph->edge;

	// Allocate memory for creating V subsets.
	struct subset *subsets = new subset[V];

	// Create V subsets with single elements
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// Initially there are V vertices in
	// contracted graph
	int vertices = V;

	// Keep contracting vertices until there are
	// 2 vertices.
	while (vertices > 2)
	{
	// Pick a random edge
	int i = rand() % E;

	// Find vertices (or sets) of two corners
	// of current edge
	int subset1 = find(subsets, edge[i].src);
	int subset2 = find(subsets, edge[i].dest);

	// If two corners belong to same subset,
	// then no point considering this edge
	if (subset1 == subset2)
		continue;
	else
	{
		printf("Contracting edge %d-%d\n",
				edge[i].src, edge[i].dest);
		vertices--;
		Union(subsets, subset1, subset2);
	}
	}

	int cutedges = 0;
	for (int i=0; i<E; i++)
	{
		int subset1 = find(subsets, edge[i].src);
		int subset2 = find(subsets, edge[i].dest);
		if (subset1 != subset2)
		cutedges++;
	}

	return cutedges;
}

int find(struct subset subsets[], int i)
{
	if (subsets[i].parent != i)
	subsets[i].parent =
			find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

// Driver program to test above functions
int main()
{
	/* Let us create following unweighted graph
		0------1
		| \ |
		| \ |
		|	 \|
		2------3 */
	int V = 4; // Number of vertices in graph
	int E = 5; // Number of edges in graph
	struct Graph* graph = createGraph(V, E);

	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	// add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;

	// add edge 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;

	// add edge 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;

	// add edge 2-3
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;

	// Use a different seed value for every run.
	srand(time(NULL));

	printf("\nCut found by Karger's randomized algo is %d\n",
		kargerMinCut(graph));

	return 0;
}


