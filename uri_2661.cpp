/**************************************************************************************************
*	11 de AGOSTO de 2018																		  *
*																								  *
*	KLEYTON SARTORI LEITE																		  *
*																								  *
*	Fatoracao de um numero em numeros primos e se os fatores do numero sao descolados             *
*       Descolados: numeros com fatores nao repetidos e formado por mais de um fator			  *
*																								  *
***************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool isprimo(long long int N)
{
    for (long int i = 2 ; i < sqrt(N) ; i++)
    {
        if(N % i == 0 || N % (N/i))
            return false;
    }
    return true;

}


inline bool isdespojado(long long int N)
{

    long long int last = 0;
    int cont = 0;

    //Verifica o dois e se ja tiver duas ocorrencias ou mais, ja tira
    while(N%2 == 0)
    {
        if(last == 2)
            return false;//return false
        //printf(" %d ", 2);
        N/=2;
        last = 2;
        cont++;
    }

    for(long long int i = 3; N > 1 ; )
    {

        if(N%i != 0)
        {
            i+=2;
        }
        else
        {
            if(last == i)return false;//return false
            //printf(" %lld ", i);
            N/=i;
            last = i;
            cont++;
        }
    }
    
    return cont > 1;

}

int main(int argc, char const *argv[])
{
    long long int N;
    long int qtd = 0;
    cin >> N;

    long long int R = sqrt(N);

    for(long long int i = 1; i <= R; i++)
    {
        if(N%i == 0)
        {   
            //é divisor
            //printf("%lld : ", i);
            if(isdespojado(i) )
            {
                //cout << " - " << i << " é descolado\n";
                qtd++;
            }
            if(isdespojado(N/i) )
            {
                //cout << " - " << i << " é descolado\n";
                qtd++;
            }
            //printf("\n");
        }
        //printf("-");
    }

    cout << qtd << '\n';
    
    return 0;
}
