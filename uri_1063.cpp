/**************************************************************************************************
*	27 de JULHO DE 2018																			  *
*																								  *
*	KLEYTON SARTORI LEITE																		  *
*																								  *
*	PROBLEMA DO URI 1063: uso de pilhas e listas limpar o maximo da pilha para inserir o proximo  *
*       item.      											                                      *
*																								  *
***************************************************************************************************/

#include <bits/stdc++.h>
#include <stack>
#include <queue>

using namespace std;


int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    while(N)
    {
        stack <char> estacao;
        queue <char> A, B;
        for(int i = 0 ; i < N; i++)
        {
            char aux;
            cin >> aux;
            A.push(aux);
        }

        for(int i = 0 ; i < N; i++)
        {
            char aux;
            cin >> aux;
            B.push(aux);
        }

        //descarrega lista de entrada
        while(!A.empty())
        {
            while(!estacao.empty()&& !B.empty() && (estacao.top() == B.front()))
            {
                cout << 'R';
                //cout << "\nRetira " << estacao.top() << " de estacao\n";
                estacao.pop();
                //cout << "\nRetira " << B.front() << " de B\n";
                B.pop();
            }
            
            estacao.push(A.front());
            cout << 'I';
            //cout << "\nRetira " << A.front()  << " de A\n";
            A.pop();
        }
        //verifica elementos restantes na pilha
        if(!estacao.empty())
        {   
            while(!estacao.empty()&& !B.empty() && (estacao.top() == B.front()))
            {
                cout << 'R';
                //cout << "\nRetira " << estacao.top() << " de estacao\n";
                estacao.pop();
                //cout << "\nRetira " << B.front() << " de B\n";
                B.pop();
            }
        }
        //se ainda houver elementos na pilha, é impossivel
        if(!estacao.empty())
            cout << " Impossible\n";
        else
            cout << '\n';

        cin >> N;
    }
    return 0;
}
