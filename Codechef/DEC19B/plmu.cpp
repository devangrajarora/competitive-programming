#include<bits/stdc++.h>
using namespace std;

int calc(int n) {
	return (n * (n - 1)) / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	for(int q = 0 ; q < t ; q++)
	{
		int zeroCnt = 0, twoCnt = 0;
		int n;
		cin >> n;

		for(int i = 0 ; i < n ; i++)
		{
			int elem;
			cin >> elem;
			if(elem == 0)
				zeroCnt++;
			if(elem == 2)
				twoCnt++;
		}

		int ans = calc(zeroCnt) + calc(twoCnt);
		cout << ans << endl;

	}

	return 0;
}	