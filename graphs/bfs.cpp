/*Program to demonstrate Breadth First Search
on a graph.
*/

#include <iostream>
#include <queue>
#include <list>
using namespace std;

class graph{
	int V;				// Total no. of vertices
	list<int> *adj;		// Pointer to the array of adjacency lists of the graph
	
	void doBfsUtil(queue<int>& q, bool* visited);	// utility function for bfs recursive
public:
	graph(int V){
		this->V = V;
		adj = new list<int> [V];
	}
	~graph(){
		delete [] adj;
	}
	void addEdge(int u,int v);	// adds an edge between u and v
	void bfs_iterative(int s);			// do a breadth first search on the graph from s
	void bfs_recursive(int s);			// recursive implementation of bfs
};

void graph::addEdge(int u,int v){
	adj[u].push_back(v);
}

void graph::doBfsUtil(queue<int>& q, bool* visited){
	// if I don't have an empty queue of vertices to visit
	if(!q.empty()){
		int u = q.front();	// get the first vertex
		q.pop();
		
		if(!visited[u]){	// if it hasn't been visited
			cout << u << " ";	// then visit it
			visited[u] = true;
		}
		
		// now for all adjacent vertex to u 
		for(auto it = adj[u].begin(); it != adj[u].end(); it++){
			// only if it hasn't been visited
			if(!visited[*it])
				q.push(*it);	// push it to the queue
		}
		
		doBfsUtil(q, visited);	// recurse for the next added vertex
	}else{
		return;
	}
	
}
void graph::bfs_recursive(int s){
	bool *visited = new bool[V];	// create an array to store which vertices are visited
	queue<int> q;		// queue for bfs
	
	for(int i = 0;i < V;i++){
		visited[i] = false;
	}
	
	q.push(s);				// push the starting node
	
	doBfsUtil(q, visited);

	delete [] visited;
}

void graph::bfs_iterative(int s){
	bool *visited = new bool[V];	// create an array to store which vertices are visited
	queue<int> q;		// queue for bfs
	list<int>::iterator it;	// Adjacency list iterator
	
	for(int i = 0;i < V;i++){
		visited[i] = false;
	}
	q.push(s);	// push the starting node to be visited
	visited[s] = true;	// visit the starting node
	
	while(!q.empty()){
		int u = q.front();	// pop the next node to be visited
		q.pop();
		cout << u << " ";	// print the node
		
		// while the poped node has elements to visit
		for(it = adj[u].begin();it != adj[u].end();it++){
			// and is not already visited
			if(visited[*it] == false){
				visited[*it] = true;	// visit it
				q.push(*it);	// enqueue it to the queue
			}
		}
	}
	
	delete [] visited;
}

int main(){
	graph g(4);		// instantiate a graph of 4 vertices
	
	// Add the edges of the directed graph
	g.addEdge(0, 1);
    	g.addEdge(0, 2);	
    	g.addEdge(1, 2);
    	g.addEdge(2, 0);
    	g.addEdge(2, 3);
    	g.addEdge(3, 3);
	
	cout << "Breadth First Search Iterative:" << endl;
	g.bfs_iterative(2);
	cout << endl;
	
	cout << "Breadth First Search Recursive:" << endl;
	g.bfs_recursive(2);
	cout << endl;
	
	return 0;
}
