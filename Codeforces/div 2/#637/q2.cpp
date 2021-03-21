#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define repe(i,n) for(int i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(int i = a ; i < b ; i++)
#define repeb(i,a,b) for(int i = a ; i <= b ; i++)
#define rfor(i,n,a) for(int i = n ; i >= a ; i--)
#define pb push_back
#define popb pop_back()
#define newLine cout << "\n"
#define endl "\n"
#define pii pair<int,int> 
#define pll pair < long long, long long >
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
#define sortv(v) sort(v.begin(),v.end())
#define rsortv(v) sort(v.begin(),v.end(), greater<>());
#define sortby(v,prop) sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop < rhs.prop; });
#define rsortby(v,prop) sort( v.rbegin( ), v.rend( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop > rhs.prop; });


/*-------------------------------------------------*/

int main()
{
	fastio;
	int tc;
	cin >> tc;

	while(tc--)
	{
		ll n, k, elem;
		unordered_map<int,int> m;

		cin >> n >> k;

		ll v[n], presum[n];
		rep(i,n) {
			cin >> elem;
			v[i] = elem;
		}

		ll c = 0;
		presum[0] = 0;

		repb(i,1,n-1) {
			if(v[i] > v[i - 1] && v[i] > v[i+1]) {
				c++;
				m[i]++;
			}
			presum[i] = c;
		}

		presum[n-1] = c;

		// rep(i,n) {
		// 	cout << presum[i] << " ";
		// }

		// cout << "\n"; 

		ll maxl = 0, maxans = 0;

		for(ll l = 0 ; l < n-k+1 ; l++) {
			ll r = l + k - 1;
			ll ans = presum[r] - presum[l];
			// cout << ans << "\n";
			if(m[l] > 0) {
				ans--;
			}

			if(m[r] > 0) {
				ans--;
			}

			ans++;
			if(ans > maxans) {
				maxans = ans;
				maxl = l;
			}
		}

		cout << maxans << " " << maxl + 1 << "\n";

	}

	return 0;
}