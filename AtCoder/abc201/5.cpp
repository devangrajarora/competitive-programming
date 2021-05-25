#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD = 1000000007;
#define fi first
#define se second
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define repe(i,n) for(int i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(int i = a ; i < b ; i++)
#define repeb(i,a,b) for(int i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define w(x) ll x; cin>>x; while(x--)

    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << " ";
            os << v[i];
            first = false;
        }
        return os;
    }
    
/*-------------------------------------------------*/

// read once, read again, think, code

const int MAXM = 2e5+1;
int timestamp = 0;
int in[MAXM];
int out[MAXM];

void dfs(int root, vi *adj, vi *depth, int d) {

	in[root] = timestamp;
	depth[d].pb(in[root]);
	timestamp++;

	for(int &child : adj[root]) {
		dfs(child,adj,depth,d+1);
	}

	out[root] = timestamp;
}

void solve() {

    int n;
    cin >> n;

    vi adj[n+1], depth[n+1];

    repeb(child,2,n) {
    	int parent; cin >> parent;
    	adj[parent].pb(child);
    }

    dfs(1,adj,depth,0);

    int q; cin >> q;

    while(q--) {
    	int u, d; cin >> u >> d;
    	int ans = lower_bound(depth[d].begin(), depth[d].end(), out[u]) - lower_bound(depth[d].begin(), depth[d].end(), in[u]);
    	p1(ans);
    }
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