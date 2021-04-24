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
    
/*-------------------------------------------------*/

// read once, read again, think, code

#define INF LLONG_MAX
 
void DP() {

	ll n, m, k, u, v, d; cin >> n >> m >> k;
	vector<pii> adj[n];

	rep(i,m) {
		cin >> u >> v >> d;
		adj[u-1].pb({v-1, d});
	}

	vi dp(n,0);    

	rep(_,k) {
		vi new_dp(n,INF);
		rep(i,n) {
			for(auto it : adj[i]) {
				if(dp[i] == INF) continue;
				new_dp[it.fi] = min(new_dp[it.fi], dp[i] + it.se);
			}
		}

		dp = new_dp;
		// p1(dp);
	}

	ll ans = *min_element(dp.begin(), dp.end());
	if(ans == INF) {
		p1("IMPOSSIBLE");
	} else {
		p1(ans);
	}
}

ll n;

struct Matrix {
	
	vvi a = vvi(n, vi(n,INF));

	Matrix operator *(const Matrix &second) {
		Matrix res;
		rep(i,n) rep(j,n) rep(k,n) {
			if(a[i][k] == INF or second.a[k][j] == INF) continue; // can't reach from i to k or k to j 
			res.a[i][j] =  min(res.a[i][j], a[i][k] + second.a[k][j]);
		}

		return res;
	}
};

Matrix matrix_expo(Matrix a, ll k) {
	Matrix result;
	rep(i,n) result.a[i][i] = 0; // no cost to reach from a point to itself in a path of length of 0
	while(k > 0) {
		if(k%2) result = result * a;
		a = a * a;
		k /= 2;
	}

	return result;
}

void solve() {

	ll m, k, u, v, d; cin >> n >> m >> k;
	Matrix board;
	rep(i,m) {
		cin >> u >> v >> d;
		u--; v--;
		board.a[u][v] = d;
	}

	Matrix res = matrix_expo(board,k);
	ll ans = INF;

	rep(i,n) rep(j,n) ans = min(ans, res.a[i][j]);
	if(ans == INF) {
		p1("IMPOSSIBLE");
	} else {
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