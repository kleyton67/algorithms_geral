#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    
    int C, V;
    scanf("\n%d \n%d", &C, &V);
    int grafo[V][3];
    //vector<list<int> > grafo;
    for (int i = 0; i <= V; i++)
    {
        for(int j = 0; j <3; j++)
        {
            scanf("\n%d", &grafo[i][j]);
        }
    }

    int dist[V];     	//guarda distancia de cada v�rtice da origem
    int anterior [V]; 	//guarda o v�rtice anterior no caminho para o destino (origem djiskra)

    //impressao
    for (int i = 0; i <= V; i++)
    {
        for(int j = 0; j <3; j++)
        {
            printf("%d ", grafo[i][j]);
        }
        printf("\n");

    }




    return 0;
}


