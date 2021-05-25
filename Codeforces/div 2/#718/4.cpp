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
#define vvvi vector<vvi>
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

ll n, m, K;


void solve() {

	cin >> n >> m >> K;

    vvvi dp(n, vvi(m, vi(K/2+1)));
    vvi horizontal(n, vi(m-1));
    vvi vertical(n-1, vi(m));

    rep(i,n) rep(j,m-1) cin >> horizontal[i][j];
    rep(i,n-1) rep(j,m) cin >> vertical[i][j];

    if(K%2) {
    	rep(i,n){rep(j,m)p0(-1);p1("");} return;
    }

    repeb(k,1,K/2) {
    	rep(i,n) {
    		rep(j,m) {
    			ll op1 = (i > 0) ? vertical[i-1][j] + dp[i-1][j][k-1] : INT_MAX; // U
    			ll op2 = (j > 0) ? horizontal[i][j-1] + dp[i][j-1][k-1] : INT_MAX; // L
				ll op3 = (i < n-1) ? vertical[i][j] + dp[i+1][j][k-1] : INT_MAX; // D
    			ll op4 = (j < m-1) ? horizontal[i][j] + dp[i][j+1][k-1] : INT_MAX; // R
    			dp[i][j][k] = min({op1,op2,op3,op4});
    		}
    	}
    }

    rep(i,n) {
    	rep(j,m) {
    		p0(2*dp[i][j][K/2]);
    	}p1("");
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