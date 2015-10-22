#include <iostream>
#include <string>

using namespace std;

bool equals(string s1, string s2)
{
	if (s1.compare(s2) == 0)
		return true;
	return false;
}

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		string front, back, left, right, top, bottom;
		cin >> front >> back >> left >> right >> top >> bottom;
		if (equals(front, left) && equals(front, top))
			cout << "YES" << endl;
		else if (equals(front, left) && equals(front, bottom))
			cout << "YES" << endl;
		else if (equals(front, right) && equals(front, top))
			cout << "YES" << endl;
		else if (equals(front, right) && equals(front, bottom))
			cout << "YES" << endl;
		else if (equals(back, left) && equals(back, top))
			cout << "YES" << endl;
		else if (equals(back, left) && equals(back, bottom))
			cout << "YES" << endl;
		else if (equals(back, right) && equals(back, top))
			cout << "YES" << endl;
		else if (equals(back, right) && equals(back, bottom))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
