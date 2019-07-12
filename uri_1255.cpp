#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    cin.ignore();

    while(n)
    {
        //implementar com string
        string palavra;

        int alfabeto[26];
        for (int i = 0; i< 26; i++)
            alfabeto[i] = 0;

        getline(cin, palavra);

        //cout << "Antes do processamento: " << palavra << '\n';

        for(int i = 0; i < palavra.size(); i++)
        {
            if((palavra[i]>='A' && palavra[i]<='Z') || (palavra[i]>='a' && palavra[i]<='z'))
            {
                palavra[i] = tolower(palavra[i]);
                alfabeto[(char)palavra[i]-'a']+=1;
                //cout << palavra[i] << " adicionado a " << (char)palavra[i]-'a' << '\n';
            }
        }
        //Fazer a impressao
        //cout << "Depois do processamento: " << palavra << '\n';

        int maior;
        maior = alfabeto[0];
        for (int i =0; i<26; i++)
        {
            if (alfabeto[i]>maior)
                maior = alfabeto[i];
        }

        //printf("maior = %d\n" ,  maior);

        for (int i =0; i<26; i++)
        {
            if (alfabeto[i]>=maior)
                printf("%c", i+97);
        }
        printf("\n");

        /* while(!palavra.empty())
            palavra.pop_back();

        */
        n--;
    }

    return 0;
}