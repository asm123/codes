using namespace std;

#include <iostream>

int main(void)
{
	int n;
	
	while(n != 42)
	{
		cin >> n;
		
		if(n != 42)
		  cout << n << endl;
		else
		  break;
		  
	}
	
	return 0;
}