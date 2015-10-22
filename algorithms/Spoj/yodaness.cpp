#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

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

long long int merge (int a[], int temp[], int low, int mid, int high)
{
	int i, j, k;
	long long int invCount = 0;
	
	i = low;
	j = mid;
	k = low;
	
	while (i <= mid-1 && j <= high)
	{
		if (a[i] > a[j])
		{
			invCount += mid - i;
			temp[k++] = a[j++];
		}
		else
			temp[k++] = a[i++];
	}
	while (i <= mid-1)
		temp[k++] = a[i++];
	while (j <= high)
		temp[k++] = a[j++];
		
	for (i = low; i <= high; i++)
		a[i] = temp[i];
	return invCount;
}

long long int merge_sort (int a[], int temp[], int low, int high)
{
	long long int invCount = 0;
	if (low < high)
	{
		int mid = low + (high - low) / 2;	
		invCount += merge_sort (a, temp, low, mid);
		invCount += merge_sort (a, temp, mid+1, high);
		invCount += merge (a, temp, low, mid+1, high);
	}
	
	return invCount;
}

long long int getInversionCount(int a[], int n)
{
	int temp[n];
	return merge_sort (a, temp, 0, n-1);
}

int main (void)
{
	int T = read();
	while (T--)
	{
		int n = read();
		string yoda_stmt[n];
		map <string, int> normal_stmt;
		int a[1000000];
		for (int i = 0; i < n; i++)
		{
			char word[100];
			scanf ("%s", word);
			yoda_stmt[i] = word;
			normal_stmt[word] = i+1;
		}
		for (int i = 0; i < n; i++)
		{
			char word[100];
			scanf ("%s", word);
			a[i] = normal_stmt[word];
		}
		printf ("%lld\n", getInversionCount (a, n));
	}
	return 0;
}
