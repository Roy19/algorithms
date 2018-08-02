// Implementation of topological sort in C++

#include <iostream>
#include <stack>
#include <list>
using namespace std;

class graph{
	int V;				// Total no. of vertices
	list<int> *adj;		// Pointer to the array of adjacency lists of the graph
	
	void topologicalSortUtil(int v, bool *visited, stack<int> &s);
public:
	graph(int V){				// constructor
		this->V = V;
		adj = new list<int> [V];
	}
	~graph(){					// destructor
		delete [] adj;
	}
	void addEdge(int u,int v);	// adds an edge between u and v
	void topologicalSort();		// do a topological sort on the graph
};

void graph::addEdge(int u,int v){
	adj[u].push_back(v);
}

void graph::topologicalSortUtil(int v, bool *visited, stack<int> &s){
	visited[v] = true;		// for vertex v, visit it
	
	// for each vertex in the adjacency list of vertex v
	for(list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++){
		if(visited[*it] == false)	// if unvisited
			topologicalSortUtil(*it, visited, s);	// visit it recursively
	}
	
	s.push(v);	// only after all the adjacent vertex have been visited and put to stack, 
				// push vertex v to the stack
}

void graph::topologicalSort(){
	bool *visited = new bool[V];
	for(int i = 0;i < V;i++){
		// mark all unexplored vertices as false
		visited[i] = false;
	}
	stack<int> s;		// auxiliary stack to store the order of vertices 
	
	for(int i = 0;i < V;i++){	// for each vertex in the disconnected graph
		if(visited[i] == false)		// if we haven't visited the vertex
			topologicalSortUtil(i,visited,s);	// do topologicalSort on the vertex
	}
	
	// print the vertices in order of topological sort
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	
	delete [] visited;
}
// Test driver function
int main(){
	graph g(6);
	
	g.addEdge(5, 0);
	g.addEdge(5, 2);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	
	g.topologicalSort();
	
	return 0;
}