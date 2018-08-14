#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Graph{
    int V;
    list< pair<int, int> > *adj;
public:
    Graph(int V){
        this->V = V;
        adj = new list< pair<int, int> > [V];
    }
    ~Graph(){
        delete [] adj;
    }

    // add an edge to the graph
    void addEdge(int u, int v, int w){
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // perform dijkstra's from the vertex src
    void dijkstraShortestPath(int src) {
        // create a priority queue with minimum element first
        priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
        // distance of the nodes from the source
        vector<int> distance(V, INT32_MAX);
        distance[src] = 0;
        
        pq.push(make_pair(src, distance[src]));

        // while the priority queue is not empty
        while(!pq.empty()){
            // pop a vertex from it
            int u = pq.top().first;
            pq.pop();
            
            // for each element in it's adjacency list of u
            for(auto it = adj[u].begin(); it != adj[u].end(); it++){
                int v = (*it).first;
                int weight = (*it).second;
                
                // relaxation condition
                if(distance[v] > distance[u] + weight){
                    // relax the vertex
                    distance[v] = distance[u] + weight;
                    // push it to the queue
                    pq.push(make_pair(v, distance[v]));
                }
            }
        }
        
        // print the weights
        cout << "Vertex" << "\t" << "Distance" << endl;
        for(int i = 0; i < V; i++){
            cout << i << "\t" << distance[i] << endl;
        }

    }
};

// Test driver
int main()
{
    int n,m;
    cin >> n >> m;
    
    Graph g(n);
    
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        
        g.addEdge(u, v, w);
    }

    g.dijkstraShortestPath(0);

    return 0;
}
