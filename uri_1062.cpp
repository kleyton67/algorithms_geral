#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
	//atribuicao = 1
	int n;
	//atribuicao = 1
	scanf("%d", &n);
	//aqui vc nao sabe quantas iteracoes ira fazer faca n(
	while(n !=0)
	{
		//stack é vetor
		//criacao é 2 (se for criacao dinamica sera n)
		stack<int> espera, auxiliar;
		//aqui vc nao sabe quantas iteracoes ira fazer faca n(
		for (int i = n; i > 0; --i)
		{
			//atribuicao = 1
			espera.push(i);
		}
		//feche o )
		//atribuicao = 1
		auxiliar = espera;
		//aqui vc nao sabe quantas iteracoes ira fazer faca n(
		while(1)
		{
			//atribuicao = 1
			espera  = auxiliar;
			//atribuicao = 1
			list<int> ordem;
			//atribuicao = 1
			int aux;
			//atribuicao = 1
			scanf("%d",  &aux);
			//comparacao = 1
			if (aux == 0)
			{
				//atribuicao = 1
				printf("\n");
				break;
			}
			else
			{
				//atribuicao = 1
				ordem.push_back(aux);
				//aqui vc nao sabe quantas iteracoes ira fazer faca n(
				for (int i = 2; i <= n; ++i)
				{
					//atribuicao = 1
					scanf("%d",  &aux);
					//atribuicao = 1
					ordem.push_back(aux);
				}
				//feche o )
			}

			//criacao é 1 (se for criacao dinamica sera n)
			stack<int> garagem;
			//atribuicao = 1
			int flag = n*2;
			//aqui vc nao sabe quantas iteracoes ira fazer faca n(
			while(flag!=0)
			{
				//aqui vc nao sabe quantas iteracoes ira fazer faca n(
				while(1){
					//comparacao = 1
					if (!garagem.empty() && (garagem.top() == ordem.front()))
					{
						//remocao = 1
						//cout << "retirou " << garagem.top() << endl;
						garagem.pop();
						//remoca = 1
						ordem.pop_front();
					}
					else 
						break;
				//feche o )
				}
				//comparacao = 1
				if(!espera.empty())
				{
					//cout << "empilhou " << espera.top() << endl;
					//atribuicao =1
					garagem.push(espera.top());
					//atribuicao =1
					espera.pop();
				}
				//comparacao = 1
				if(ordem.empty())
					break;
				//atribuicao = 1
				flag--;
			//feche o )
			}

			//cout << ordem.front();
			//comparacao = 1
			if(ordem.empty())
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
			//aqui vc nao sabe quantas iteracoes ira fazer faca n(
			while(!garagem.empty())
			{
				//atribuicao = 1
				garagem.pop();
			}//feche o )

		}//feche o )

		scanf("%d", &n);
	}//feche o )

	return 0;
}

/*
	Complexidade do algoritmo = 4n⁴ + 14n + 2n + 2
*/#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
	//atribuicao = 1
	int n;
	//atribuicao = 1
	scanf("%d", &n);
	//aqui vc nao sabe quantas iteracoes ira fazer faca n(
	while(n !=0)
	{
		//stack é pilha
		//criacao é 1 (se for criacao dinamica sera n)
		stack<int> espera, auxiliar;
		//aqui vc nao sabe quantas iteracoes ira fazer faca n(
		for (int i = n; i > 0; --i)
		{
			//atribuicao = 1
			espera.push(i);
		}
		//feche o )
		//atribuicao = 1
		auxiliar = espera;
		//aqui vc nao sabe quantas iteracoes ira fazer faca n(
		while(1)
		{
			//atribuicao = 1
			espera  = auxiliar;
			//atribuicao = 1
			list<int> ordem;
			//atribuicao = 1
			int aux;
			//atribuicao = 1
			scanf("%d",  &aux);
			//comparacao = 1
			if (aux == 0)
			{
				//atribuicao = 1
				printf("\n");
				break;
			}
			else
			{
				//atribuicao = 1
				ordem.push_back(aux);
				//aqui vc nao sabe quantas iteracoes ira fazer faca n(
				for (int i = 2; i <= n; ++i)
				{
					//atribuicao = 1
					scanf("%d",  &aux);
					//atribuicao = 1
					ordem.push_back(aux);
				}
				//feche o )
			}

			//criacao é 1 (se for criacao dinamica sera n)
			stack<int> garagem;
			//atribuicao = 1
			int flag = n*2;
			//aqui vc nao sabe quantas iteracoes ira fazer faca n(
			while(flag!=0)
			{
				//aqui vc nao sabe quantas iteracoes ira fazer faca n(
				while(1){
					//comparacao = 1
					if (!garagem.empty() && (garagem.top() == ordem.front()))
					{
						//remocao = 1
						//cout << "retirou " << garagem.top() << endl;
						garagem.pop();
						//remoca = 1
						ordem.pop_front();
					}
					else 
						break;
				//feche o )
				}
				//comparacao = 1
				if(!espera.empty())
				{
					//cout << "empilhou " << espera.top() << endl;
					//atribuicao =1
					garagem.push(espera.top());
					//atribuicao =1
					espera.pop();
				}
				//comparacao = 1
				if(ordem.empty())
					break;
				//atribuicao = 1
				flag--;
			//feche o )
			}

			//cout << ordem.front();
			//comparacao = 1
			if(ordem.empty())
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
			//aqui vc nao sabe quantas iteracoes ira fazer faca n(
			while(!garagem.empty())
			{
				//atribuicao = 1
				garagem.pop();
			}//feche o )

		}//feche o )

		scanf("%d", &n);
	}//feche o )

	return 0;
}

/*
	Complexidade do algoritmo = 4n⁴ + 14n + 2n + 2
*/
