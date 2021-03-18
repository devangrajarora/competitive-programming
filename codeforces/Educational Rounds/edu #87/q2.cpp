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
		string s;
		cin >> s;
		int n = s.size();
		int one = -1, two = -1, three = -1, ans = INT_MAX;

		rep(i,n) {

			if(s[i] == '1') {
				one = i;
			} else if(s[i] == '2') {
				two = i;
			} else {
				three = i;
			}

			int l = min(one,min(two,three));
			int r = max(one,max(two,three));

			if(l != -1) {
				int len = r - l + 1;
				ans  = min(ans,len);
			}

		}

		if(ans == INT_MAX) {
			cout << 0 << "\n";
		} else {
			cout << ans << "\n";
		}

	}

	return 0;
}