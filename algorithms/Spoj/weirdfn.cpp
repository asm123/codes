using namespace std;

#include <iostream>
#include <queue>

int main(void)
{
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++)
	{
		long long int a,b,c;
		int n;
		priority_queue <long long int, vector<long long int>, greater<long long int> > min;
		priority_queue <long long int> max;
		long long int sum = 1;
		long long int median;
		cin >> a >> b >> c >> n;
		
		if(n == 1)
		{
			cout << "1" << endl;
			continue;
		}
		
		max.push(1);
		
		for(int j = 2; j<=n; j++)
		{
			if(max.size() >= min.size())
			  median = max.top();
			else
			  median = min.top();
			
			long long int x = (a * median + b * j + c) % 1000000007;
			
			while(x < 0)
			    x += 1000000007;
			
			sum += x;
				
			if(x <= max.top())
			  max.push(x);
			else
			  min.push(x);
			
			long long int min_size = min.size();
			long long int max_size = max.size();
	
			if((min_size - max_size) > 1)
			{
				max.push(min.top());
				min.pop();
			}
			else if((max_size - min_size) > 1)
			{
				min.push(max.top());
				max.pop();
			}
		}
		cout << sum << endl;
	}
	
	return 0;
}
