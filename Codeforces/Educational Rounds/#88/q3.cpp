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

ld temp(ll h, ll c, ll nh, ll nc) {
	return (nh*h*1.0 + nc*c) / (nh+nc);
}

int main()
{
	fastio;
	int tc;
	cin >> tc;

	while(tc--)
	{
		ll h, c, t, cups = 0, curr = 0;
		cin >> h >> c >> t;

		ld av = (h + c) / (2*1.0);
		
		if(h == t) {
			p1(1);
		} else if(t <= av) { // av will only increase
			p1(2);
		} else {

			// rounded down
			ll k = (t - h) / (h  + c - 2 * t);
			k = 2 * k + 1;

			ll nh = (k + 1) / 2;
			ll nc = nh - 1;

			// p2(temp(h,c,nh,nc),temp(h,c,nh+1,nc+1));

			ld op1 = abs(temp(h,c,nh,nc) - t); 
			ld op2 = abs(temp(h,c,nh+1,nc+1) - t);

			// p4("op1:",op1,"op2:",op2); 

			ll ans = (op1 <= op2) ? k : k + 2;
			p1(ans);
		}
	}

	return 0;
}