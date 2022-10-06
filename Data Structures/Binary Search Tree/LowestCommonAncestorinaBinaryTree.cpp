//Arvind kumar <Avrvindk314@gmail.com>
#include <bits/stdc++.h>

#define sz(x) x.size()
#define pb push_back
#define left 2 * i + 1
#define right 2 * i + 2
using namespace std;

const int maxn = 100005;

// the graph
vector<vector<int>> g(maxn);

// level of each node
int level[maxn];

vector<int> e;
vector<int> l;
int h[maxn];

// the segment tree
int st[5 * maxn];

// adding edges to the graph(tree)
void add_edge(int u, int v) {
g[u].pb(v);
g[v].pb(u);
}

// assigning level to nodes
void leveling(int src) {
for (int i = 0; i < sz(g[src]); i++) {
	int des = g[src][i];
	if (!level[des]) {
	level[des] = level[src] + 1;
	leveling(des);
	}
}
}

bool visited[maxn];

// storing the dfs traversal
// in the array e
void dfs(int src) {
e.pb(src);
visited[src] = 1;
for (int i = 0; i < sz(g[src]); i++) {
	int des = g[src][i];
	if (!visited[des]) {
	dfs(des);
	e.pb(src);
	}
}
}

// making the array l
void setting_l(int n) {
for (int i = 0; i < sz(e); i++)
	l.pb(level[e[i]]);
}

// making the array h
void setting_h(int n) {
for (int i = 0; i <= n; i++)
	h[i] = -1;
for (int i = 0; i < sz(e); i++) {
	// if is already stored
	if (h[e[i]] == -1)
	h[e[i]] = i;
}
}

// Range minimum query to return the index
// of minimum in the subarray L[qs:qe]
int RMQ(int ss, int se, int qs, int qe, int i) {
if (ss > se)
	return -1;

// out of range
if (se < qs || qe < ss)
	return -1;

// in the range
if (qs <= ss && se <= qe)
	return st[i];

int mid = (ss + se) >> 1;
int st = RMQ(ss, mid, qs, qe, left);
int en = RMQ(mid + 1, se, qs, qe, right);

if (st != -1 && en != -1) {
	if (l[st] < l[en])
	return st;
	return en;
} else if (st != -1)
	return st;
else if (en != -1)
	return en;
}

// constructs the segment tree
void SegmentTreeConstruction(int ss, int se, int i) {
if (ss > se)
	return;
if (ss == se) // leaf
{
	st[i] = ss;
	return;
}
int mid = (ss + se) >> 1;

SegmentTreeConstruction(ss, mid, left);
SegmentTreeConstruction(mid + 1, se, right);

if (l[st[left]] < l[st[right]])
	st[i] = st[left];
else
	st[i] = st[right];
}

// Function to get LCA
int LCA(int x, int y) {
if (h[x] > h[y])
	swap(x, y);
return e[RMQ(0, sz(l) - 1, h[x], h[y], 0)];
}

// Driver code
int main() {

// n=number of nodes in the tree
// q=number of queries to answer
int n = 15, q = 5;

// making the tree
/*
				1
				/ | \
				2 3 4
				| \
				5 6
				/ | \
			8 7 9 (right of 5)
				/ | \ | \
			10 11 12 13 14
					|
					15
*/
add_edge(1, 2);
add_edge(1, 3);
add_edge(1, 4);
add_edge(3, 5);
add_edge(4, 6);
add_edge(5, 7);
add_edge(5, 8);
add_edge(5, 9);
add_edge(7, 10);
add_edge(7, 11);
add_edge(7, 12);
add_edge(9, 13);
add_edge(9, 14);
add_edge(12, 15);

level[1] = 1;
leveling(1);

dfs(1);

setting_l(n);

setting_h(n);

SegmentTreeConstruction(0, sz(l) - 1, 0);

cout << LCA(10, 15) << endl;
cout << LCA(11, 14) << endl;

return 0;
}
