/* Contributed by - Ritik kumar <arp17114865@gmail.com> */

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
	vector<int> bfs_traversal;
	vector<bool> vis(V, false);
	for (int i = 0; i < V; ++i) {
		
		
		if (!vis[i]) {
			queue<int> q;
			vis[i] = true;
			q.push(i);
			
			
			while (!q.empty()) {
				int g_node = q.front();
				q.pop();
				bfs_traversal.push_back(g_node);
				for (auto it : adj[g_node]) {
					if (!vis[it]) {
						vis[it] = true;
						q.push(it);
					}
				}
			}
		}
	}
	return bfs_traversal;
}
