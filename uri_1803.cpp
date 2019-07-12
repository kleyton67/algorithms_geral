#include <iostream>
#include <string>
#include <vector>

#include <cstddef>



using namespace std;


int main(int argc, char const *argv[])
{
    vector<string> matring(4);

    for(int i=0; i < 4; i++)
    {
        cin >> matring[i];
    }

    string primer;
    for(int i =0; i < 4; i++)
    {
        primer.push_back(matring[i][0]);
    }
    primer.push_back('\0');
    //Numero da primeira coluna F
    int num_primer ;
    num_primer = stoi(primer, nullptr, 10);

    string last;
    for(int i =0; i < 4; i++)
    {
        last.push_back(matring[i][matring[i].size()-1]);
    }
    //Numero da ultima coluna
    last.push_back('\0');
    int num_last = stoi(last);

    for(int i=1; i < matring[0].size()-1; i++)
    {
        string Mi;
        int num_M;
        for(int j =0; j < 4; j++)
        {
            Mi.push_back(matring[j][i]);
        }
        //Mi.push_back('\0');
        num_M = stoi(Mi);
        /*cout << num_primer << '>' << num_last << '>' << num_M << '>' <<
         Mi << '\n';  */
        cout <<(char)((num_primer*num_M+num_last)%257);
    }
    cout << '\n';

    return 0;
}
