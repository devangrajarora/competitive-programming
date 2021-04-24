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

void DP() {

	ll n, m, k, u, v;
	cin >> n >> m >> k;
    vi adj[n], dp(n,1);

    rep(i,m) {
    	cin >> u >> v;
    	adj[u-1].pb(v-1);
    }

    for(int i = 1 ; i<= k ; i++) {
    	vi newDP(n);

    	for(int a = 0 ; a < n ; a++) {
    		for(auto b : adj[a]) {
    			newDP[b] = (newDP[b] + dp[a]) % MOD;
    		}
    	}

    	dp = newDP;
    }

    p1(accumulate(dp.begin(), dp.end(),0));
}

int n;

struct Matrix {
	
	vvi a = vvi(n,vi(n));

	Matrix operator *(const Matrix &second) {
		Matrix product;
		rep(i,n) rep(j,n) rep(k,n) {
			product.a[i][j] =  (product.a[i][j] + ((a[i][k] * second.a[k][j]) % MOD) ) % MOD;
		}

		return product;
	}
};

Matrix matrix_expo(Matrix a, ll k) {
	Matrix result;
	rep(i,n) result.a[i][i] = 1; // identity matrix
	while(k > 0) {
		if(k%2) result = result * a;
		a = a * a;
		k /= 2;
	}

	return result;
}

void solve() {
	
	int m; 
	ll k, ans = 0;
	
	cin >> n >> m >> k;
	Matrix adj;

	rep(i,m) {
		int u, v;
		cin >> u >> v;
		adj.a[u-1][v-1] = 1;
	}

	Matrix res = matrix_expo(adj,k);

	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			ans = (ans + res.a[i][j]) % MOD;
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