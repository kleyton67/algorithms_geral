#include <string>
#include <iomanip>//setw
#include <string.h>
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<string> palavra;
    int n, m=0;

    scanf("%d", &n);

    while(n > 0)
    {
        int tamanho = 0;

        for(int i=0 ; i < n; i++)
        {    
            string pal;
            cin >> pal;
            palavra.push_back(pal);
            unsigned int aux = palavra[i].size();
            if(aux > tamanho) 
                tamanho = aux;
        }

        for(int i = 0 ; i < n; i++)
        {
            cout << setw(tamanho) <<  palavra[i];
            cout << '\n';
        }
        scanf("%d", &n);
        if(n>0)
            cout << '\n';
        m++;
        palavra.clear();
    }
    return 0;
}