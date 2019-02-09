#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int prim(vector< vector< pair<int, int> > > &adj, int start){
	// the visited vertex set
	bool visited[adj.size()]{false};
	int mst_weight = 0;
	// priority queue keyed on the weights of neighbouring vertices
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
	pq.push(make_pair(0, start));

	while(!pq.empty()){
		// extract the next minimum weighted vertex
		int u = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		
		// if it belongs to the unvisited category, 
		// then only is it of any importance
		if(visited[u] == false){
			mst_weight += w;
			visited[u] = true;
			// then update the weights of the adjacent vertices from it
			for(auto v: adj[u]){
				if(visited[v.first] == false){
					pq.push(make_pair(v.second, v.first));
				}
			}
		}
	}

	return mst_weight;
}

int main(){
	// n-> # nodes, m-> # edges
	int n, m, x, y, w;
	cin >> n >> m;
	vector< vector< pair<int, int> > > adj_list(n+1);

	for(int i = 0;i < m;i++){
		// fill up the adjacency list
		cin >> x >> y >> w;
		adj_list[x].push_back(make_pair(y, w));
		adj_list[y].push_back(make_pair(x, w));
	}

	cout << prim(adj_list, x) << endl;
}