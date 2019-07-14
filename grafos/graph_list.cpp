
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
    bool isCyclicUtil(int v, bool visited[], bool recStack[]) ;
    bool isCyclic();
    void topologicalSortUtil(int v, bool visited[],  
                                stack<int> &Stack) ;
    void topologicalSort(); 
    void countPathsUtil(int u, int d, bool visited[], 
                                        int &pathCount) ;
    int countPaths(int s, int d) ;
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


// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(int v, bool visited[],  
                                stack<int> &Stack) 
{ 
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
  
    // Push current vertex to stack which stores result 
    Stack.push(v); 
} 
  
// The function to do Topological Sort. It uses recursive  
// topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to store Topological 
    // Sort starting from all vertices one by one 
    for (int i = 0; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 
  
    // Print contents of stack 
    while (Stack.empty() == false) 
    { 
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
} 
  
// A recursive function that uses visited[] and parent to detect 
// cycle in subgraph reachable from vertex v. 
// This function is a variation of DFSUytil() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    {  
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
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
    // stack 
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    memset(visited, false, sizeof(visited));
    memset(recStack, false, sizeof(recStack)); 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for (int u = 0; u < V; u++) 
        if (!visited[u]) // Don't recur for u if it is already visited 
          if (isCyclicUtil(u, visited, recStack)) 
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

 
// A recursive function to print all paths  
// from 'u' to 'd'. visited[] keeps track of  
// vertices in current path. path[] stores  
// actual vertices and path_index is  
// current index in path[] 
void Graph::countPathsUtil(int u, int d, bool visited[], 
                                        int &pathCount) 
{ 
    visited[u] = true; 
  
    // If current vertex is same as destination,  
    // then increment count 
    if (u == d) 
        pathCount++; 
  
    // If current vertex is not destination 
    else
    { 
        // Recur for all the vertices adjacent to 
        // current vertex 
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (!visited[*i]) 
                countPathsUtil(*i, d, visited,  
                                      pathCount); 
    } 
  
    visited[u] = false; 
} 
  
 
// Returns count of paths from 's' to 'd' 
int Graph::countPaths(int s, int d) 
{ 
      
    // Mark all the vertices 
    // as not visited 
    bool *visited = new bool[V]; 
    memset(visited, false, sizeof(visited)); 
  
    // Call the recursive helper 
    // function to print all paths 
    int pathCount = 0; 
    countPathsUtil(s, d, visited, pathCount); 
    return pathCount; 
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
