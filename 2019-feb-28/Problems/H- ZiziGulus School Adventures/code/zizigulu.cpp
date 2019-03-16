#include <iostream>

using namespace std;

int main()
{
	long long int n = 0, i = 0, j = 0, sum = 0;

	cin >> n;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (i < 1 || j < 5)
			{
				sum += max((long long)0, n - i - j + 1);
			}
		}
	}

	cout << sum;

	return 0;
}
