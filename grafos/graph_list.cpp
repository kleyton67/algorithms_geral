
// Grafos em C++
/*
    Kleyton Leite

    Compilado de grafos com listas

    Fonte: https://www.geeksforgeeks.org/

    Arquivo: graph_list.cpp
 */

#include<bits/stdc++.h> 
using namespace std; 
  
// Graph class represents a directed graph 
// using adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing 
    // adjacency lists 
    list<int> *adj; 
  
    // A recursive function used by DFS 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // DFS traversal of the vertices 
    // reachable from v 
    void DFS(int v); 
    void BFS(int s);
    //detectar ciclos em grafos(adaptação de BFS)
    bool isCyclicUtil(int v, bool visited[], int parent) ;
    bool isCyclic();

}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
/*
    DFS pode gerar arvore minima
    Detectar ciclos
    Achar caminhos entre dois vertices
        -> Usando uma pilha para guardar os vertices pelo caminho
    Verificar se um grafo eh fortemente conectado
        -> computar o DFS de cada vertice
        -> fazer a traposta do grafo
        -> DFS novamente
    
 */
void Graph::DFS(int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    memset(visited, false, sizeof(visited)); 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited); 
} 

  
// A recursive function that uses visited[] and parent to detect 
// cycle in subgraph reachable from vertex v. 
bool Graph::isCyclicUtil(int v, bool visited[], int parent) 
{ 
    // Mark the current node as visited 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    { 
        // If an adjacent is not visited, then recur for that adjacent 
        if (!visited[*i]) 
        { 
           if (isCyclicUtil(*i, visited, v)) 
              return true; 
        } 
  
        // If an adjacent is visited and not parent of current vertex, 
        // then there is a cycle. 
        else if (*i != parent) 
           return true; 
    } 
    return false; 
} 

/*
    Pode ser usado para detectar ciclos em apenas um vertice
    para isso usar apenas a isCyclicUtil(v, visited, -1)
 */
// Returns true if the graph contains a cycle, else false. 
bool Graph::isCyclic() 
{ 
    // Mark all the vertices as not visited and not part of recursion 
    // stack 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for (int u = 0; u < V; u++) 
        if (!visited[u]) // Don't recur for u if it is already visited 
          if (isCyclicUtil(u, visited, -1)) 
             return true; 
  
    return false; 
} 

/*
    BFS pode:
        gerar arvore minima para grafos com arestas não ponderadas
 */
void Graph::BFS(int s) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
  
    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 
  
// Driver code 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 
  
    return 0; 
} 
