#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int > vetor;
	int n, conts, pos;

	//recebe total de casos
	cin >> n;

	int pessoas, pulo;
	//controla os casos
	for (int i = 0; i < n ; ++i)
	{
		//recebe pessoas e pulo
		cin >> pessoas ;
		cin >> pulo;

		//contador do vetor
		pos = 0;

		//preenche o vetor 
		for (int p = 0; p < pessoas; ++p)
		{
			vetor.push_back(p);
		}

		conts = 1;

		while(vetor.size() > 1){

			//Inicio do algoritmo de suicidio

			if(conts == pulo){
				//exclui elemento do vetor e atualiza flag
				//cout << "Excluindo : " << vetor[pos] << '\n';
				vetor.erase(vetor.begin()+pos);
				conts = 1;
				pos--;	
			}
			else
				conts++;
			//se o contador chego no ultimo elemento resetar 
			pos++;
			if(pos == vetor.size()){
				pos =0;
			}

		}

		cout << "Case " << n << ": " <<vetor.front() +1<< '\n';
		vetor.clear();
	}

	return 0;
}