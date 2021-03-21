#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    
/*-------------------------------------------------*/

// read once, read again, think, code

ll func(ll n, ll T, vvi &dp, vi &t) {
	if(dp[n][T] != -1) return dp[n][T];
	if(n == 0) {
		dp[n][T] = 0;
	} else if(T == 0 and n != 0) {
		dp[n][T] = INT_MAX;
	} else {
		ll pick = abs(T-t[n-1]) + func(n-1,T-1,dp,t);
		ll noPick = func(n,T-1,dp,t);
		dp[n][T] = min(pick, noPick);
	}

	return dp[n][T];
}

void solve() {

    ll n, ans = 0; cin >> n;
    vi t(n);
    rep(i,n) cin >> t[i];
    sort(t.begin(), t.end());
    
    vvi dp(n+1, vi(2*n+1,-1));
    p1(func(n,2*n, dp,t));
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