#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	
	unsigned int a, b, carry, total;

	while(scanf("%u %u", &a, &b)!= EOF){

		carry = a&b;

		total = a^b;

		cout << total << '\n';
	}


	return 0;
}