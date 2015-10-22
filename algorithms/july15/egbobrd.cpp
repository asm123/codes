#include <iostream>

using namespace std;

int main (void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int days;
		unsigned long long int pieces_per_package;
		cin >> days >> pieces_per_package;
		unsigned int pieces_per_day[days];
		unsigned long long int left = pieces_per_package, packages = 1;
		
		for (int i = 0; i < days; i++)
			cin >> pieces_per_day[i];
		for (int i = 0; i < days; i++)
		{
			if (left > 0)
			{
				if (left >= pieces_per_day[i])
				{
					left -= pieces_per_day[i];
					if (left > 0)
						left--;
				}
				else
				{
					int pieces_required = pieces_per_day[i];
					pieces_required -= left;
					int packages_required = pieces_required / pieces_per_package;
					if (pieces_required % pieces_per_package == 0)
					{
						packages += packages_required;
						left = 0;
					}
					else
					{
						packages_required++;
						packages += packages_required;
						left = pieces_per_package * packages_required - pieces_required - 1;
					}
				}
			}
			else if (left == 0)
			{
				int pieces_required = pieces_per_day[i];
				int packages_required = pieces_required / pieces_per_package;
				if (pieces_required % pieces_per_package == 0)
				{
					packages += packages_required;
					left = 0;
				}
				else
				{
					packages_required++;
					packages += packages_required;
					left = pieces_per_package * packages_required - pieces_required - 1;
				}
			}
		}
		cout << packages << endl;
	}
	return 0;
}
