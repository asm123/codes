#include <stdio.h>
#include <cmath>

bool isPalindrome (int);
bool isPrime (int);

inline int read ()
{
	char c;
	int n = 0;

	while ((c = getchar_unlocked ()) < 48);
	n += (c - '0');
	
	while ((c = getchar_unlocked ()) >= 48)
	  n = n * 10 + (c - '0');
	
	return n;
}

int main (void)
{
	int n = read ();
	if (n >= 98609)
	  printf ("1003001\n");
	else
	{
		for (int i = n; ; i++)
		{
			if (isPrime(i) && isPalindrome(i))
			{
				printf ("%d\n", i);
				break;
			}
		}
	}
	
	return 0;
}

bool isPrime (int n)
{
	if (n == 2 || n == 3)
	  return true;
	int i;
	for (i = 2; i <= sqrt (n); i++)
	{
		if (n % i == 0)
		  return false;
	}
	if (i == sqrt(n))
	  return false;
	return true;
}

bool isPalindrome (int n)
{
	int num = n, rev = 0;
	while (num > 0)
	{
		rev = rev * 10 + num % 10;
		num /= 10;
	}
	if (n == rev)
	  return true;
	return false;
}