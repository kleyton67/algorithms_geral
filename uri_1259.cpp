#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
	set<int> impar, par;
	set<int>::iterator it_impar, it_par;
	int n;
	scanf("\n%d", &n);
	while(n > 0)
	{
		int var;
		scanf("\n%d", &var);
		if(var%2 == 0)
		{
			par.insert(var);
			//printf("par = %d\n", var);
		}
		else
		{
			impar.insert(var);
			//printf("impar = %d\n, var");
		}
		n--;
	}

	for(it_par = par.begin(); it_par != par.end(); it_par++)
		printf("%d\n", *it_par);

	int i=0;
	for(i = 0, it_impar = impar.end() ; it_impar != impar.begin() ; --it_impar, i++ ){
		if(i != 0)
			printf("%d\n", *it_impar);
	}
	printf("%d\n", *it_impar);
	return 0;
}