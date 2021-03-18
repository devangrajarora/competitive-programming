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
#define rsortby(v,prop) sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop > rhs.prop; });


/*-------------------------------------------------*/

int main()
{
	fastio;
	int tc;
	cin >> tc;

	while(tc--)
	{
		ll n, even = 0, odd = 0, num;
		bool f = false;
		cin >> n;

		unordered_map<ll,ll> m;

		rep(i,n) {
			cin >> num;
			if(num % 2 == 0) {
				even++;
			} else {
				odd++;
			}

			m[num]++;
			if(m[num - 1] > 0 || m[num + 1] > 0) {
				f = true;
			}
		}

		if(odd % 2 == 0 && even % 2 == 0) {
			cout << "YES\n";
		} else {
			if(f) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}

	}

	return 0;
}