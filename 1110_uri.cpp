/*
Kleyton Leite

Exercicio do URI numero 1110, implementacao 
basica de fila com queue
*/

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{

	queue <int> fila, aux;
	vector<int> v;

	int a, inicio;

	cin >> a;

	while(a != 0){
		if(a == 1){
			cout << "Discarded card: " ;

			cout << '\n';

			cout << "Remaining card: " << 1 << '\n';
		}
		else
		{

			for (int i = 1; i <= a; ++i)
			{
				fila.push(i);
			}

			while(fila.size() != 1){
				v.push_back(fila.front());
				fila.pop();
				inicio = fila.front();
				fila.push(inicio);
				fila.pop();
			}

			cout << "Discarded cards: ";
			int i = 0;
			while(i < v.size()-1){
				cout << v[i] << ", " ;
				i++;
			}

			cout << v[i] << '\n';

			cout << "Remaining card: " << fila.front()<< '\n';
			fila.pop();
		//Limpa vector
			v.clear();
		}
		cin >> a;


	}

	return 0;
}