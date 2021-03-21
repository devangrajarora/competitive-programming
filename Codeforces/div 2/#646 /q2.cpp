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

		ll n = s.size(), one = 0, zero = 0;
		
		rep(i,n) {
			if(s[i] == '1') {
				one++;
			} else {
				zero++;
			}
		}

		ll ans = min(one,zero);

		ll dp[n]{0};
		if(s[0] == '0') {
			dp[0] = 1;
		}

		if(s[0] == '0') {
			ans = min(zero - 1, one + 1);
		} else {
			ans = min(zero + 1, one - 1);
		}


		ll op1, op2;
		repb(i,1,n) {

			dp[i] = dp[i - 1];
			if(s[i] == '0') {
				dp[i]++;
			} 

			ll lOnes = i + 1 - dp[i], lZeroes = dp[i];
			ll rOnes = one - lOnes, rZeroes = zero - lZeroes;

			op1 = (rOnes) + (lZeroes);// 00111
			op2 = (rZeroes) + (lOnes);// 111000

			ans = min(ans, min(op1,op2));
		}

		p1(ans);

	}

	return 0;
}