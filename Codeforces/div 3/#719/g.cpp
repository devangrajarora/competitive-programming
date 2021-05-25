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
#define vi vector<ll>
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

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
    
/*-------------------------------------------------*/

// read once, read again, think, code

#define vb vector<bool>

ll n, m, w;

bool valid(ll i, ll j) {
	return 0 <= i and i < n and 0 <= j and j < m;
}

struct Portal {
	ll i;
	ll j;
	ll cost;
};

void dijkstra(vector<pii> *adj) {

	vi distance(n*m+1,LLONG_MAX);
	vb vis(n*m+1,false);

	multiset<pii> q;
	q.insert({0,0});
	distance[0] = 0;

	while(!q.empty()) {

		pii x = *q.begin();
		q.erase(x);
		if(vis[x.se]) continue;
		vis[x.se] = true;
		distance[x.se] = x.fi;

		for(auto it : adj[x.se]) {
			if(!vis[it.fi]) {

				ll newDist = distance[x.se] + it.se;
				ll currDist = distance[it.fi];
				if(currDist > newDist) {
					q.insert({newDist, it.fi});
				}
			}
		}
	}

	ll ans = (distance[n*m-1] == LLONG_MAX) ? -1 : distance[n*m-1];
	p1(ans);
}


void solve() {

    cin >> n >> m >> w;
    vvi a(n, vi(n));
    vector<Portal> portals;

    rep(i,n) {
    	rep(j,m) {
    		cin >> a[i][j];
    		if(a[i][j] > 0) {
    			portals.pb({i,j,a[i][j]});
    		}
    	}
    }

    int portalCnt = 0, portalsz = portals.size();

    vector<pii> adj[n*m];

    rep(i,n) {
    	rep(j,m) {
    		
    		if(a[i][j] == -1) continue;

    		ll from = i*m+j;

    		if(a[i][j] > 0) { // portal
    			for(int k = portalCnt ; k < portalsz ; k++) {
    				Portal next = portals[k];
    				ll to = next.i * m + next.j;
    				ll wt = next.cost + a[i][j];
    				adj[from].pb({to,wt});
    				adj[to].pb({from,wt});
    			}

    			portalCnt++;
    		}

    		rep(k,4) {
    			ll ni = i + dr4[k];
    			ll nj = j + dc4[k];
    			if(valid(ni,nj) and a[ni][nj] != -1) {
    				ll to = ni * m + nj;
    				adj[from].pb({to,w});
    				adj[to].pb({from,w});
    			}
    		}
    	}
    }

    dijkstra(adj);
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    solve();
	
	return 0;
}