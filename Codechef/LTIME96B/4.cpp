#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD = 1000000007;
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

const ll ninf = -1e12;

void solve() {

    ll n, k; cin >> n >> k;
    vi a(n+1);
    rep(i,n) cin >> a[i+1];
    vvvi dp(n+1, vvi(k+1, vi(3,ninf)));

    repe(i,n) {
    	repe(j,min(k,i)) {

            if(i == 0 or j == 0) {
                rep(x,3) dp[i][j][x] = 0;
                continue;
            }

    		ll joining = max({dp[i-1][j][0],dp[i-1][j][1]});
    		ll bestOfAll = max({dp[i-1][j-1][0],dp[i-1][j-1][1], dp[i-1][j-1][2]});

    		ll append = joining + j * a[i]; // include
    		ll startNew = bestOfAll + j * a[i]; // exclude
            ll leave = max({dp[i-1][j][0],dp[i-1][j][1],dp[i-1][j][2]});

            dp[i][j][0] = append;
            dp[i][j][1] = startNew;
            dp[i][j][2] = leave;
    	}
    }

    ll ans = max({dp[n][k][0],dp[n][k][1],dp[n][k][2]});
    p1(ans);
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