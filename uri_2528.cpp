/**************************************************************************************************
*	11 de AGOSTO de 2018							                                      											  *
*																								                                                  *
*	KLEYTON SARTORI LEITE																		                                        *
*																								                                                  *
*	Uso de djikstra para resolução do problema                                      			          *
*                                                                                                 *   
*   Fonte: https://www.sanfoundry.com                                                             *
*																								                                                  *
***************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Graph{
    protected:
        int V;//quantidade de vertices
        list<int> adj[10000];//lista de ponteiros para inteiros

    public:
        Graph(int V){
            this->V = V;
        }
        void addEdge(int v, int w);
        int* dijkstra(int orig);
        void remove(int dest);
        void delete_g();
        int getNodes()
        {
          return V;
        }

        ~Graph(){
          for(int i = 0; i < V; i++){
            adj[i].clear();
          }
        }

};

void Graph::addEdge(int v, int w){
    /*
        Adiciona o aresta para conectar v e w, (v->w)
    */
   adj[v].push_back(w);
}

int* Graph::dijkstra(int orig)
	{
		// vetor de distâncias
		int * dist = new int [V];

		/*
		   vetor de visitados serve para caso o vértice já tenha sido
		   expandido (visitado), não expandir mais
		*/
		int visitados[V];

		// fila de prioridades de pair (distancia, vértice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de distâncias e visitados
		for(int i = 0; i < V; i++)
		{
			dist[i] = INT_MAX;
			visitados[i] = false;
		}

		// a distância de orig para orig é 0
		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		// loop do algoritmo
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obtém o vértice do pair
			pq.pop(); // remove da fila

			// verifica se o vértice não foi expandido
			if(visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<int>::iterator it;

				// percorre os vértices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// obtém o vértice adjacente e o custo da aresta
					int v = *it;
					int custo_aresta = 1;

					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a distância de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a distância mínima até o destino
		return dist;
	}

void Graph::remove(int dest){
  for(int i = 0 ; i < V; i++)
  {
    adj[i].remove(dest);
  }
  adj[dest].clear();
}

void Graph::delete_g()
{
    for(int i = 0; i <= V; i++){
              while(!adj[i].empty())
                adj[i].pop_back();
  }
}

int main(int argc, char const *argv[])
{
  int N = 0;
    while(scanf("\n%d", &N)!= EOF)
    {
      Graph g(N);
      int M = 0;
      scanf("\n%d", &M);

      for(int i=0; i < M; i++)
      {
        int A = 0, B = 0;
        scanf("\n%d\n%d", &A, &B);

        g.addEdge( A-1, B-1);
      }
      int C = 0, R= 0, E= 0;
      scanf("\n%d\n%d\n%d", &C , &R, &E);
      g.remove(E-1);
      int* distancias = g.dijkstra(C-1);

      cout << distancias[R-1] << '\n';
      g.delete_g();
      delete distancias;
    }
    return 0;
}
