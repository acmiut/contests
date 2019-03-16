#include<bits/stdc++.h>

using namespace std;

int main()
 {
	long long N;
	cin >> N;
	vector<long long> ans;

	for (long long i = 1; i*i <= N; ++i)
	 {
		if (N%i==0) //if i divides N
		{
			ans.push_back(N*(i-1)/2 + i);//sum of arithmetic series
			if (i*i!=N) //unless i = sqrt(N)
			{
				ans.push_back(N*(N/i-1)/2 + N/i); //sum of arithmetic series produced by the inverse divisor of i
			}
		}
	}
	sort(ans.begin(),ans.end());

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}