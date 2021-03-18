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


/*-------------------------------------------------*/

int ecnt, vcnt;
unordered_map<int,int> edges;

void dfs(vector<int> *adj, int st, vector<bool> &vis) {
    
    vis[st] = true;
	vcnt++;
	ecnt += edges[st];

    for(auto it : adj[st]) {
        if(!vis[it]) {
            dfs(adj,it,vis);
        }
    }
}

void solve() {

	int n, m, u,v, cnt = 0, ans = 0;
	cin >> n >> m;

	vector<int> adj[n+1];
	vector<bool> vis(n+1,false);

	for(int i = 0 ; i < m ; i++) {
		cin >> u >> v;
		edges[u]++;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for(int i = 1 ; i <= n ; i++) {

		if(vis[i]) continue;
		ecnt = 0, vcnt = 0;
		dfs(adj,i,vis);
		ans += (ecnt - (vcnt-1));
	}

	cout << ans << "\n";
}


int main()
{
	fastio;
	solve();
	return 0;
}