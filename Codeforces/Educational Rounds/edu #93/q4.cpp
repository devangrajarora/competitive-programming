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
#define pii pair<int,int> 
#define pll pair < long long, long long >
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

ll nCr(ll n, ll r) { 
    ll res = 1; 
    if (r > n - r) {
        r = n - r; 
    }
    rep(i,r) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
    return res; 
}

bool isPrime(long long n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}


/*-------------------------------------------------*/

#define vi vector<ll>
#define vvi vector<vi>
#define vvvi vector<vvi>

void solve() {
	
	ll nr, ng, nb;
	cin >> nr >> ng >> nb;

	vector<int> r(nr), g(ng), b(nb);
	
	rep(i,nr) cin >> r[i];
	rep(i,ng) cin >> g[i];
	rep(i,nb) cin >> b[i];

	rsortv(r);
	rsortv(g);
	rsortv(b);

	vvvi dp(nr+1, vvi(ng+1, vi(nb+1, 0)));

	int i = 0, j = 0, k = 0;
	ll ans = 0;

	// dp[i][j][k] -> max area obtained by taking
	// i largest red sticks
	// j largest green sticks
	// k largest blue sticks

	for(int i = 0 ; i <= nr ; i++) {
		for(int j = 0 ; j <= ng ; j++) {
			for(int k = 0 ; k <= nb ; k++) {

				if(i < nr && j < ng) {
					ll include = dp[i][j][k] + r[i]*g[j];
					ll notinclude = dp[i+1][j+1][k];
					dp[i+1][j+1][k] = max(notinclude, include);
				}

				if(i < nr && k < nb) {
					ll include = dp[i][j][k] + r[i]*b[k];
					ll notinclude = dp[i+1][j][k+1];
					dp[i+1][j][k+1] = max(include, notinclude);
				}

				if(j < ng && k < nb) {
					ll include = dp[i][j][k] + g[j]*b[k];
					ll notinclude = dp[i][j+1][k+1];
					dp[i][j+1][k+1] = max(include, notinclude);
				}

				ans = max(ans, dp[i][j][k]);
			}
		}
	}

	p1(ans);
}


int main()
{
	fastio;
	solve();
	return 0;
}