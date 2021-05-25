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

void solve() {

    ll n; cin >> n;

    vi a(n), b(n), prefix(n), suffix(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    rep(i,n) {
    	if(i > 0) prefix[i] = prefix[i-1];
    	prefix[i] += a[i]*b[i];
    }

    rfor(i,n-1,0) {
    	if(i < n-1) suffix[i] = suffix[i+1];
    	suffix[i] += a[i]*b[i];
    }

    vvi dp(n, vi(n));

    rfor(i,n-1,0) {
    	repb(j,i,n) {
    		if(i == j) dp[i][j] = a[i]*b[i];
    		else if(i+1 == j) dp[i][j] = a[i]*b[j] + a[j]*b[i];
    		else {
    			dp[i][j] = dp[i+1][j-1] + a[i]*b[j] + b[i]*a[j];
    		}
    	}
    }

    // rep(i,n) p1(dp[i]);

    ll ans = prefix[n-1];

    rep(i,n) {
    	repb(j,i+1,n) {
    		ll curr = 0;
    		if(i > 0) curr += prefix[i-1];
    		if(j < n-1) curr += suffix[j+1];
    		curr += dp[i][j];
    		ans = max(ans, curr);
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