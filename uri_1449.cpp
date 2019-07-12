#include <iostream>
#include <map>
#include <string>

using namespace std;


int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while(T>0)
    {
        map <string, string> dicionario;
        string palavra, traducao;
        int M, N;

        cin >> M;
        cin  >> N;
        cin.ignore();
        while(M>0)
        {
            getline(cin, palavra, ' ');
            getline(cin, traducao);
            dicionario[palavra] = traducao;
            M--;
        }
/*
        cout << "Mapeamento: \n";
        for(auto mapeamento = dicionario.begin(); mapeamento!=dicionario.end() ;mapeamento++)
        {
            cout << mapeamento->first << " - " << mapeamento->second << '\n';
        }
*/
        cin.ignore();
        palavra.clear();
        while(N)
        {
            //https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
            getline(cin, palavra);
            cout << palavra << " - " << dicionario[palavra] << '\n';
            N--;
        }
        cout << "Size : " << dicionario.size() << '\n';
        cout << '\n';

        T--;
    }
    return 0;
}
