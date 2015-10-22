#include <cstdio>

long long int merge (int a[], int temp[], int low, int mid, int high)
{
	int i, j, k;
	long long int invCount = 0;
	
	i = low;
	j = mid;
	k = low;
	
	while (i <= mid - 1 && j <= high)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			invCount += (mid - i);
		}
	}
	while (i <= mid - 1)
		temp[k++] = a[i++];
	while (j <= high)
		temp[k++] = a[j++];
		
	for (i = low; i <= high; i++)
		a[i] = temp[i];
	
	return invCount;
}

long long int mergeSort (int a[], int temp[], int low, int high)
{
	int mid;
	long long int invCount = 0;
	if (low < high)
	{
		mid = low + (high - low) / 2;
		invCount = mergeSort (a, temp, low, mid);
		invCount += mergeSort (a, temp, mid + 1, high);
		invCount += merge (a, temp, low, mid + 1, high);
	}
	return invCount;
}

long long int getInversionCount (int a[], int n)
{
	int temp[n];
	return mergeSort (a, temp, 0, n - 1);
}

int main (void)
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		int n;
		scanf ("%d", &n);
		int a[n];
		for (int i = 0; i < n; i++)
			scanf ("%d", &a[i]);
		printf ("%lld\n", getInversionCount (a, n));
	}
	return 0;
}
