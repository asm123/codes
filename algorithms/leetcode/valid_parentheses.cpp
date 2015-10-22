#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{	
	private:
		stack <char> st;
	
	public:
		bool isValid (string s)
		{
			for (unsigned int i = 0; i < s.length(); i++)
			{
				switch(s[i])
				{
					case '(':
					case '{':
					case '[':
						st.push (s[i]);
						break;
					case ')':
						if (st.empty() || st.top() != '(')
							return false;
						st.pop();
						break;
					case '}':
						if (st.empty() || st.top() != '{')
							return false;
						st.pop();	
						break;
					case ']':
						if (st.empty() || st.top() != '[')
							return false;
						st.pop();
						break;
				}
			}
			if (!st.empty())
				return false;
			while (!st.empty())
				st.pop();
			return true;
		}
};

int main (void)
{
	string s;
	cin >> s;
	Solution sol;
	cout << sol.isValid (s) << endl;
	return 0;
}
