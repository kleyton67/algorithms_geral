/**************************************************************************************************
*	22 de JULHO DE 2018																			  *
*																								  *
*	KLEYTON SARTORI LEITE																		  *
*																								  *
*	PROBLEMA DO URI 1022: USO DO ALGORITMO EUCLIDIANO PARA RESOLUÇÃO DE PROBLEMAS RELACIONADOS AO *
*		MDC 																					  *
*																								  *
***************************************************************************************************/

#include <iostream>
#include <stdlib.h>

//CABEÇALHOS
//ALGORITMO EUCLIDIANO
long long int algoritmo_euclidiano(long long int a, long long int b)
{
	if(b == 0)
		return a;
	else
		algoritmo_euclidiano(b, a%b);
}

int main()
{
	int N;
	std::cin >> N;
	while (N--)
	{
		long long int N1, D1, N2, D2;
		char C1, C2;
		int numerador = 0;
		int denominador = 0;
		std::cin >> N1;
		std::cin >> C1;
		std::cin >> D1;
		std::cin >> C2;
		std::cin >> N2;
		std::cin >> C1;
		std::cin >> D2;

		switch (C2)
		{
		case '+':
		{
			numerador = (N1*D2 + N2 * D1);
			denominador = (D1*D2);
			break;
		}
		case '-':
		{
			numerador = (N1*D2 - N2 * D1);
			denominador = (D1*D2);
			break;
		}
		case '*':
		{
			numerador = (N1*N2);
			denominador = (D1*D2);
			break;
		}
		case '/':
		{
			numerador = (N1*D2);
			denominador = (N2*D1);
			break;
		}
		}

		long long int mdc = algoritmo_euclidiano(numerador, denominador);	
		if((denominador/mdc) < 0)
			printf("%d/%d = %d/%d\n", numerador, denominador, (-1)*(numerador/mdc), (-1)*(denominador/mdc));
		else if(denominador < 0)
			printf("%d/%d = %d/%d\n", (-1)*numerador, (-1)*denominador, numerador/mdc, denominador/mdc);
		else
			printf("%d/%d = %d/%d\n", numerador, denominador, numerador/mdc, denominador/mdc);


	}
	
	return 0;
}

