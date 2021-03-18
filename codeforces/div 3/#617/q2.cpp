#include<bits/stdc++.h>
#define ll long long int 
#define MOD 1000000007
// #define FOR(i,n) for(int i = 0 ; i < n ; i++)
// #define FOR(i,a,b) for(int i = a ; i < b ; i++)
#define pb push_back
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCases;
	cin >> testCases;

	for(int it = 0 ; it < testCases ; it++)
	{
		ll n, ans = 0;
		cin >> n;

		while(n > 9)
		{
			ll digit = n % 10;
			ll num = n - digit;
			ans += num;
			n = digit + (num / 10); 
		}

		ans += n;

		cout << ans << "\n";
	}

	return 0;
}