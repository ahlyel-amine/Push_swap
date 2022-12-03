#include <iostream>
// #include <cstdlib>
#include  <stdlib.h>
using namespace std;

int main(){

	int i;
	int random;

	i = 1;
	// Providing a seed value
	srand((unsigned) time(NULL));
	// Loop to get 5 random numbers
	while (i <= 300)
	{

		// Retrieve a random number between 100 and 200
		// Offset = 100
		// Range = 101
		if (!(i % 5))
		random = 900 + (rand() % 101);
		else if (!(i % 3))
		random = 800 + (rand() % 105);
		else if (!(i % 4))
		random = 700 + (rand() % 106);
		else if (!(i % 2))
		random = 500 + (rand() % 107);
		else
		random = 400 + (rand() % 109);
	printf("%d\n",random);
		// cout<<random<<endl;
		i++;
	}
	return 0;
}
