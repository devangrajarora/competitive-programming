#include<bits/stdc++.h>
#define ll long long int 
#define MOD 1000000007
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	int n, ans;
	for(int q = 0 ; q < t ; q++)
	{
		ans = 0;
		cin >> n;

		for(int i = 0 ; i < n ; i++)
		{
			int s, p, v;
			cin >> s >> p >> v;
			s++;
			int num = v * (p/s);
			if(num > ans)
				ans = num;
		}

		cout << ans << endl;
	}

	return 0;
}