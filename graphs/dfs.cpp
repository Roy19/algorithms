// Do Depth First Search on a Graph
#include <iostream>
#include <list>
using namespace std;

class graph{
    int V;              // total no of vertices in the graph
    list<int> *adj;     // array of adjacency list for each vertex

    void doDFS(int v,bool * visited);   // actual DFS recursive function
public:
	graph(int V);   // constructor
    ~graph();       // destructor

    void addEdge(int u,int v);  // add an edge between u and v
    void dfs(int s);            // start doing dfs on graph from s
};

graph::graph(int V){
    this->V = V;
    adj = new list<int> [V];
}
graph::~graph(){
    delete [] adj;
}

void graph::addEdge(int u,int v){
    adj[u].push_back(v);
}

void graph::dfs(int s){
    // first make a list of vertices we have visited
    bool *visited = new bool[V];
    for(int i = 0;i < V;i++){
        // initially we haven't visited any
        visited[i] = false;
    }

    visited[s] = true;  // visit the starting vertex
    doDFS(s, visited);  // dfs from it

    delete [] visited;
}

void graph::doDFS(int v, bool * visited){
    list<int>::iterator it;
    cout << v << " ";       // print the vertex being currently visited

    // for each vertex adjacent to v
    for(it = adj[v].begin();it != adj[v].end();it++){
        // if we haven't already visited them   
        if(visited[*it] == false){
            visited[*it] = true;    // visit them
            doDFS(*it, visited);    // do DFS for vertices now adjacent to it
        }
    }
}

// Test driver program
int main(){
    // Create a graph given in the above diagram
    graph g(4);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 0);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.dfs(2);
 
    return 0;
}
