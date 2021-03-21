#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define popb pop_back()
#define endl "\n"
#define pii pair < long long, long long >
typedef priority_queue<ll, vector<ll>, greater<ll>> minheap;
typedef priority_queue<ll> maxheap;
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

ll modPower(ll num,ll r){
	if(r==0) return 1;
	if(r==1) return num%MOD;
	ll ans=modPower(num,r/2)%MOD;
	if(r%2==0) {
		return (ans*ans)%MOD;
	} return (((ans*ans)%MOD)*num)%MOD;
}

/*-------------------------------------------------*/

#define vi vector<int>
#define vvi vector<vi>

ll k, d;

int func(ll n, bool cond, vvi &dp) {

	if(n == 0) {
		return cond ? 1 : 0;
	}

	if(dp[n][cond] != -1) return dp[n][cond];

	if(n < d && !cond) {
		dp[n][cond] = 0;
		return 0;
	}

	ll x = min(n,k), ans = 0;
	for(int i = 1 ; i <= x ; i++) {

		if(cond) {
			ans = (ans + func(n-i,cond,dp))%MOD;
		} else {
			if(i < d) {
				ans = (ans + func(n-i, cond, dp))%MOD;
			} else {
				ans = (ans + func(n-i,true,dp))%MOD;
			}
		}
	}

	dp[n][cond] = ans%MOD;
	return dp[n][cond];
}

void solve() {

	ll n;
	cin >> n >> k >> d;
	vvi dp(n+1, vi(2,-1));

	ll ans = func(n,false,dp);
	p1(ans);
}


int main()
{
	fastio;
	solve();
	return 0;
}