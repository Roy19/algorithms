#include <iostream>
#include <cstring>
using namespace std;

/*
 * Check if a graph has a cycle or not using Union-Find algorithm.
 * Edges are represented as a set of pairs (u,v). Where the edge is from u to v.
 * Graph here is an undirected graph.
 *
*/

typedef struct edge{
	// each edge pair (u,v)
	int src, dest;
}edge;

class graph{
	int V, E;	// V = no. of vertices, E = no. of edges
	edge * edges;	// set of the edges of the graph
public:
	graph(int V, int E);
	~graph();
	
	void setEdge(int i, int u, int v);
	bool isCyclic();
	int Find(int i, int * parent);	// find operation on a disjoint set
	void Union(int * parent, int x, int y);	// takes the union of the set in which x and y are	
};

graph::graph(int V, int E){
	this->V = V;
	this->E = E;

	// dynamically allocated edge set
	edges = new edge[this->E];
}

graph::~graph(){
	this->V = 0;
	this->E = 0;

	delete [] edges;
}

void graph::setEdge(int i, int u, int v){
	this->edges[i].src = u;
	this->edges[i].dest = v;
}

int graph::Find(int i, int * parent){
	// TODO : make an iterative version
	
	// if i node has no parent
	if(parent[i] == -1)
		return i;

	// else node i is present in the set of it's parent
	// we need to find the set it's parent is in
	return this->Find(parent[i], parent);
}

void graph::Union(int * parent, int x, int y){
	// int xset = this->Find(x, parent);
	// int yset = this->Find(y, parent);
	
	parent[x] = y;	// or vice-versa
}

bool graph::isCyclic(){
	// first create a parent array to denote which vertex has which parent
	int * parent = new int[V];
	// firstly each edge is undiscoverded and hence each vertex has no parent (each is a singleton).
	memset(parent, -1, sizeof(int) * V);

	// for each edge in the graph
	for(int i = 0;i < E;i++){
		// find two end vertices of that edge
		// determine which set are they in
		int x = this->Find(edges[i].src, parent);
		int y = this->Find(edges[i].dest, parent);
		
		// if both are in the same set, then the graph must be cyclic
		if (x == y){
			delete [] parent;	
			return true;
		}
		// else take their union
		this->Union(parent, x, y);
	}	

	delete [] parent;
	return false;
}

// Test driver program
int main(){
	// create a new graph of 3 vertices, 3 edges
	graph g(5,4);

	// add edges
	g.setEdge(0, 0, 1);
	//g.setEdge(1, 1, 2);
	g.setEdge(1, 1, 3);
	g.setEdge(2, 1, 4);
	g.setEdge(3, 0, 2);

	if (g.isCyclic())
		cout << "Graph is cyclic" << endl;
	else
		cout << "Graph isn't cyclic" << endl;

	return 0;
}

