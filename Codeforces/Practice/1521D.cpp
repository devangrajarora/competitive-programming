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

#define MAXM 100001

struct Cut {
	int x, y;
};

void p(Cut op) {
	cout << op.x << " " << op.y << " "; 
}

vector<Cut> cuts;
int cutParent[MAXM];
vi leaves;

int dfs(vi *adj, int curr, int parent, vi &ans, vi *adj2, int makeLeaf) {

	int childCnt = 0, leaf = curr, sz = adj[curr].size() - (parent != -1);
	
	if(parent != -1 and sz >= 2) {
		cutParent[curr] = 1;
		// watch(curr);
		cuts.pb({parent,curr});
	}

	for(auto &child : adj[curr]) {
		if(child != parent) {
			int ml = (--sz);
			leaf = dfs(adj,child,curr,ans,adj2, ml == 1);

			if(childCnt == 2) {
				cuts.pb({curr,child});
			} else {
				childCnt++;
			}
		}
	}

	if(childCnt == 0 and makeLeaf) {
		leaves.pb(curr);
	}

	return leaf;
}

void solve() {

	cuts.clear();
	leaves.clear();
	memset(cutParent,0,sizeof(cutParent));
    ll n, a, b;
    cin >> n;
    vi adj[n+1], adj2[n+1];
    vi ans(n+1,0);

    rep(i,n-1) {
    	cin >> a >> b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }

    ll lastLeaf = dfs(adj,1,-1,ans,adj2,0);


    int yes = 1;
    for(auto &child : adj[1]) {
    	if(cutParent[child] == 0) {
    		yes = 0;
    	}
    }

    if(yes) leaves.pb(1);

    // p1(leaves);
    // for(Cut &cut : cuts) {
    // 	p(cut);
    // }

    int i = 0;
    for(Cut &cut : cuts) {
    	p(cut);p2(leaves[i], leaves[i+1]);
    	i++;
    }
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    w(tc)
    	solve();
	
	return 0;
}