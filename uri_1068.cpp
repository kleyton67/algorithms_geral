/**************************************************************************************************
*	27 de JULHO DE 2018																			  *
*																								  *
*	KLEYTON SARTORI LEITE																		  *
*																								  *
*	PROBLEMA DO URI 1068: Balanco de parenteses com pilhas										  *
*																								  *
***************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    
    string aux;
    cin >> aux;
    while(!cin.eof())
    {
        stack<char> par;
        bool flag = false;
        for(string :: iterator it = aux.begin(); it!= aux.end() ; it ++)
        {
            if(*it == '(')
            {
                //cout << "Colocou em par\n";
                par.push(*it);
            }
            else if((*it == ')') && !par.empty())
            {
                //cout << "Retirou do par\n";
                par.pop();
            }
            else if((*it == ')') && par.empty())
                {
                    flag = true;
                    break;
                }
        }
        if(par.empty() && !flag)
            cout << "correct\n";
        else
            cout << "incorrect\n";

        aux.clear();
        cin >> aux;
    }

    return 0;
}
