/**************************************************************************************************
*	22 de JULHO DE 2018																			  *
*																								  *
*	KLEYTON SARTORI LEITE																		  *
*																								  *
*	PROBLEMA DO URI 1023: USANDO UM VETOR PARA RESOLUÇÃO DO PROBLEMA E OPCOES PARA TRUNCAMENTO 	  *
*																								  *
***************************************************************************************************/
#include <iostream>

using namespace std;



int main(int argc, char const *argv[])
{
    int N, i = 0;
    cin >> N; 
    while(N!=0)
    {
        int total_consumo = 0, total_pessoas = 0;
        int cidade [201];
        for(int z = 0 ; z < 201; z++)
        {
            cidade[z] = 0;
        }
        while(N--)
        { 
            int pessoas, consumo;

            cin >> pessoas;
            cin >> consumo;
            total_consumo += consumo;
            total_pessoas += pessoas;

            cidade[consumo/pessoas] += pessoas;

        }


        cout << "Cidade# " << i+1 <<":\n";
        for(int j = 0; j < 201; j++)
        {
            if(cidade[j] > 0)
                cout << cidade[j] << '-' << j << ' ';
        }
        cout << '\n';
        float media = (float)(total_consumo/(float)total_pessoas);

        /*char media_c [5];
        sprintf(media_c, "%0.3f\n", media);
        printf(media_c);*/

        //printf("Consumo medio: %.3f\b m3.\n", media);//\b trunca o numero
        int m = (int)(media *100);
        media = (float)m / 100;
        printf("Consumo medio: %.2f m3.\n", media);

        cin >> N;
        i++;

    }

    return 0;
}
