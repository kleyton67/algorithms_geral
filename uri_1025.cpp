/**************************************************************************************************
*	26 de JULHO DE 2018																			  *
*																								  *
*	KLEYTON SARTORI LEITE																		  *
*																								  *
*	PROBLEMA DO URI 1025: pesquisa especial em vetor											  *
*																								  *
***************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void preenchimento(int vetor[], int valor, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vetor[i] = valor;
    }
}

int find_ultimate_cons(
    vector<int>::iterator begin,
    vector<int>::iterator end, 
    int valor, 
    int marcador 
)//encontra sempe o valor na maior posicao consecutiva
{
    vector<int> :: iterator it;
    int i = 1;
    for(it = begin ;it != end; ++it, ++i)
    {
        if(*it == valor)
        {
            //if(*(it+1) == valor)
              //  continue;
            //else
                return i;
        }
    }

    return -1;
}

bool ordenar_ascendente(int i, int j)
{
    return j > i;
}

int main(int argc, char const *argv[])
{
    
    int N, Q;

    cin >> N;
    cin >> Q;

    int i = 1;

    vector<int> Raju;

    while(N && Q)
    {
        
        for(int i = 0; i < N; i++)
        {
            int aux;
            cin >> aux;// ordenar o vetor
            Raju.push_back(aux);
        }

        //ordenar o vetor ascendentemente
        sort(Raju.begin(), Raju.end(), ordenar_ascendente);

        vector<int> :: iterator it = Raju.begin();
        /*cout << "Impressao do vetor: \n";
        for(; it!=Raju.end(); it++)
        {
            cout << *it << '\n';
        }
        cout << "Fim da impressão";*/

        cout << "CASE# " << i << ':' << '\n'; 
        for(int z = 0; z < Q; z++)
        {
            int aux;
            cin >> aux;
            int pos = find_ultimate_cons(Raju.begin(), Raju.end(), aux, -1);
            if(pos > -1)
                cout << aux << " found at " << pos << '\n';
            else
                cout << aux << " not found" << '\n';
        }

        cin >> N;
        cin >> Q;
        i++;

        Raju.erase(Raju.begin(), Raju.end());
        //cout << "Tamanho do vetor: " << Raju.size() << '\n';
    }

    return 0;
}
