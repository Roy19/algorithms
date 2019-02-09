#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_NODES 10001

int grand_parent[MAX_NODES];

void initialize(){
	for(int i = 0;i < MAX_NODES;i++){
		// initially each child is its own grandparent
		grand_parent[i] = i;
	}
}

int root(int x){
	while(grand_parent[x] != x){
		grand_parent[x] = grand_parent[grand_parent[x]];
		x = grand_parent[x];
	}

	return grand_parent[x];
}

void union1(int x, int y){
	int a = root(x);
	int b = root(y);

	grand_parent[a] = grand_parent[b];
}

int kruskal(vector< pair<int, pair<int, int>> > &edges){
	// initialization
	initialize();
	int mst_weight = 0;

	for(auto edge: edges){
		// for each edge
		int x = edge.second.first;
		int y = edge.second.second;
		int w = edge.first;

		// it forms our required solution if both are not already connected
		if(root(x) != root(y)){
			union1(x, y);
			mst_weight += w;
		}
	}

	return mst_weight;
}

int main(){
	// n-> # nodes, m-> # edges
	int n, m;
	cin >> n >> m;
	vector< pair<int, pair<int, int>> > edges(m);
	for(int i = 1;i <= m;i++){
		// edge between x, y with weigth = weight
		int x, y, weight;
		cin >> x >> y >> weight;
		edges[i-1] = make_pair(weight, make_pair(x, y));
	}
	// sort in increasing order of weights
	sort(edges.begin(), edges.end());

	cout << kruskal(edges) << endl;
}