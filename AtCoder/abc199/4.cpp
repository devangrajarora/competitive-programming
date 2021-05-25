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
#define vi vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair <ll,ll>
typedef priority_queue<ll, vector<ll>, greater<ll>> minheap;
typedef priority_queue<ll> maxheap;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define w(x)  ll x; cin>>x; while(x--)

    template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

    template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
{
	bool first = true;
	os << "[";
	for(unsigned int i = 0; i < v.size(); i++)
	{
		if(!first)
			os << ", ";
		os << v[i];
		first = false;
	}
	return os << "]";
}

    template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
{
	bool first = true;
	os << "[";
	for (typename std::set<T>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
	{
		if(!first)
			os << ", ";
		os << *iii;
		first = false;
	}
	return os << "]";
}

    template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
{
	bool first = true;
	os << "[";
	for (typename std::map<T1, T2>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
	{
		if(!first)
			os << ", ";
		os << *iii ;
		first = false;
	}
	return os << "]";
}

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code

#define vb vector<bool>

vi adj[21];
vb vis(21, false);
int color[21];
vi component;
ll n;

void dfs(ll curr) {
	component.pb(curr);
	vis[curr] = 1;
	for(auto it : adj[curr]) {
		if(!vis[it]) {
			dfs(it);
		}
	}
}

ll dfs1(ll idx) {
	if(idx == component.size()) return 1;

	ll ans = 0;

	for(int c = 0 ; c < 3 ; c++) {
		int ok = 1;
		for(auto &it : adj[component[idx]]) {
			if(c == color[it]) ok = 0;
		}

		if(ok) {
			color[component[idx]] = c;
			ans += dfs1(idx+1);
			color[component[idx]] = -1;
		}
	}

	return ans;
}

void solve() {

	ll m, ans = 1, u, v; cin >> n >> m;
	rep(i,m) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	repeb(i,1,n) {
		if(!vis[i]) {
			component.clear();
			dfs(i);

			ll currAns = 0;

			for(ll c  = 0 ; c < 3 ; c++) {

				memset(color,-1,sizeof(color));
				color[component[0]] = c;
				currAns += dfs1(1);
			}

			ans *= currAns;
		}
	}

	p1(ans);
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
	freopen("/home/devang/input.txt","r",stdin);
	freopen("/home/devang/output.txt","w",stdout);
    #endif

    //w(tc)
	solve();
	
	return 0;
}