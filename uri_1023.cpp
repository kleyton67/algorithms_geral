/**************************************************************************************************
*	25 de JULHO DE 2018																			  *
*																								  *
*	KLEYTON SARTORI LEITE																		  *
*																								  *
*	PROBLEMA DO URI 1023: USO DE MAP															  *
*																								  *
***************************************************************************************************/
#include <iostream>
#include <map>

using namespace std;



int main(int argc, char const *argv[])
{
    int N, i = 0;
    cin >> N; 
    while(N!=0)
    {
        int total_consumo = 0, total_pessoas = 0;
        map <int , int> cidade;
        while(N--)
        { 
            int pessoas, consumo;

            cin >> pessoas;
            cin >> consumo;
            total_consumo += consumo;
            total_pessoas += pessoas;

            cout << pessoas << ' ';
            cout << consumo << '\n';

            map<int, int>::iterator procurado = cidade.find(consumo/pessoas);

            if(procurado!=cidade.end())
            {
                procurado->second += pessoas;
            }
            else
                cidade.insert(pair<int , int>(consumo/pessoas, pessoas));

        }

        cout << "Cidade# " << i+1 <<":\n";
        map <int , int> :: iterator it = cidade.begin();
        for (it = cidade.begin(); it != cidade.end(); ++it)
        {
            cout << it->second << '-' << it->first << ' ';
        }

        cout << '\n';
        printf("Consumo medio: %.2f m3.\n", (float)(total_consumo/(float)total_pessoas));

        cin >> N;
        i++;

    }

    return 0;
}
