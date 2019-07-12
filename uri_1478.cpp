#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a, aux, flag, loop = 0;	

	cin >> a;

	while(a!=0){
		if(loop !=0)
			cout << '\n';

		int matriz[a][a];
		
		for (int i = 0; i < a; ++i)
		 {
		 	flag = true;
		 	aux = i;
		 	for (int j = 0; j < a; ++j)
		 	{
		 		if(i == 0)
		 			matriz[i][j] = 	j;
		 		else {

		 			if(aux < 0){
		 				flag = false;
		 				aux = 1;
		 			}
		 			if(flag == true ){
		 				matriz[i][j] = aux;
		 				aux--;
		 			}
		 			if(flag == false)
		 			{
		 				matriz[i][j] = aux;
		 				aux++;
		 			}
		 		}
		 	}
		 } 


		for (int i = 0; i < a; ++i)
			 {
			 	for (int j = 0; j < a; ++j)
			 	{
			 			cout <<' '<< matriz[i][j]+1;
			 	}
			 	cout << '\n';
			} 
		cin >> a;
		loop++;
	}
}