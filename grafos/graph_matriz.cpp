#include <bits/stdc++.h>
#include <limits.h> 

using namespace std;

class Graph{
    private:
        vector<vector<int> > graph;
        int V;//tamanho do grafo
    public:
        Graph(int vertices);
        void addEdge(int v, int d, int width);
        //BFS para fordFulkerson
        bool BFS_ford(vector<vector<int> > rGraph, int s, int t, int parent[]);
        //Resolução do problema de fluxo em grafos
        int fordFulkerson(int s, int t);
        bool isBipartite(int source);
};

Graph::Graph(int vertices)
{
    V = vertices;
    graph.resize(V);
    for(int i ; i < V; i++){
        graph[i].resize(V);
    }
}


void Graph::addEdge(int v, int d, int weight)
{
    graph[v][d] = weight;
}

/* Returns true if there is a path from source 's' to sink 't' in 
  residual graph. Also fills parent[] to store the path */
bool Graph::BFS_ford(vector<vector<int> > rGraph, int s, int t, int parent[]) 
{ 
    // Create a visited array and mark all vertices as not visited 
    bool visited[V]; 
    memset(visited, 0, sizeof(visited)); 
  
    // Create a queue, enqueue source vertex and mark source vertex 
    // as visited 
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
  
    // Standard BFS Loop 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        for (int v=0; v<V; v++) 
        { 
            if (visited[v]==false && rGraph[u][v] > 0) 
            { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        } 
    } 
  
    // If we reached sink in BFS starting from source, then return 
    // true, else false 
    return (visited[t] == true); 
} 

// Returns the maximum flow from s to t in the given graph
//fonte: https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
int Graph::fordFulkerson(int s, int t) 
{ 
    int u, v; 
  
    // Create a residual graph and fill the residual graph with 
    // given capacities in the original graph as residual capacities 
    // in residual graph 
    vector<vector<int> > rGraph(graph.begin(), graph.end()); // Residual graph where rGraph[i][j] indicates  
                     // residual capacity of edge from i to j (if there 
                     // is an edge. If rGraph[i][j] is 0, then there is not)   
  
    int parent[V];  // This array is filled by BFS and to store path 
  
    int max_flow = 0;  // There is no flow initially 
  
    // Augment the flow while tere is path from source to sink 
    while (BFS_ford(rGraph, s, t, parent)) 
    { 
        // Find minimum residual capacity of the edges along the 
        // path filled by BFS. Or we can say find the maximum flow 
        // through the path found. 
        int path_flow = INT_MAX; 
        for (v=t; v!=s; v=parent[v]) 
        { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]); 
        } 
  
        // update residual capacities of the edges and reverse edges 
        // along the path 
        for (v=t; v != s; v=parent[v]) 
        { 
            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 
  
        // Add path flow to overall flow 
        max_flow += path_flow; 
    } 
  
    // Return the overall flow 
    return max_flow; 
} 

// This function returns true if graph  
// G[V][V] is Bipartite, else false 
bool Graph::isBipartite(int src) 
{ 
    // Create a color array to store colors  
    // assigned to all veritces. Vertex  
    // number is used as index in this array.  
    // The value '-1' of colorArr[i]  
    // is used to indicate that no color  
    // is assigned to vertex 'i'. The value 1  
    // is used to indicate first color  
    // is assigned and value 0 indicates  
    // second color is assigned. 
    int colorArr[V]; 
    for (int i = 0; i < V; ++i) 
        colorArr[i] = -1; 
  
    // Assign first color to source 
    colorArr[src] = 1; 
  
    // Create a queue (FIFO) of vertex  
    // numbers and enqueue source vertex 
    // for BFS traversal 
    queue <int> q; 
    q.push(src); 
  
    // Run while there are vertices  
    // in queue (Similar to BFS) 
    while (!q.empty()) 
    { 
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 ) 
        int u = q.front(); 
        q.pop(); 
  
        // Return false if there is a self-loop  
        if (graph[u][u] == 1) 
        return false;  
  
        // Find all non-colored adjacent vertices 
        for (int v = 0; v < V; ++v) 
        { 
            // An edge from u to v exists and  
            // destination v is not colored 
            if (graph[u][v] && colorArr[v] == -1) 
            { 
                // Assign alternate color to this adjacent v of u 
                colorArr[v] = 1 - colorArr[u]; 
                q.push(v); 
            } 
  
            // An edge from u to v exists and destination  
            // v is colored with same color as u 
            else if (graph[u][v] && colorArr[v] == colorArr[u]) 
                return false; 
        } 
    } 
  
    // If we reach here, then all adjacent   
    // vertices can be colored with alternate color 
    return true; 
} 