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
#define vb vector<bool>
int fullM;

int dfs(vi *adj, vb &vis, int *cat, int st, int m) {

	m = (cat[st]) ? m-1 : fullM;
	vis[st] = true;

	if(adj[st].size() == 1 && st > 0) { // leaf node
		return (m >= 0);
	}
	
	if(m < 0) return 0;
	int ans = 0;

	for(auto it : adj[st]) {
		if(!vis[it]) {
			ans += dfs(adj,vis,cat,it,m);
		}
	}

	return ans;
}

void solve() {
	
	int n, m, u, v;
	cin >> n >> m;
	int cat[n];
	rep(i,n) cin >> cat[i];

	vector<int> adj[n];
	rep(i,n-1) {
		cin >> u >> v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}

	vb vis(n,false);
	fullM = m;
	int ans = dfs(adj,vis,cat,0,m);
	p1(ans);
}


int main()
{
	fastio;
	solve();
	return 0;
}