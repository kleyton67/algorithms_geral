#include <iostream>
#include <string>

using namespace std;

int main (){
	int n;
	cin >> n;
	while(n>0){
		string entrada;
		//cin.clear();
		cin >> entrada;
		int aberto =0;
		int fechado = 0;
		for(int i=0; i<entrada.size(); i++){
			if(entrada[i] == '<')
				aberto ++;
			if(entrada[i] == '>' && aberto>0){
				fechado++;
				aberto--;
			}
		}
		cout << fechado << '\n';
		n--;
	}

	return 0;	
}