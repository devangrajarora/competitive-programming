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

// O(n^2) dp

void dp() {

	ll n; cin >> n;
	vi a(n), dp(n,0);
	rep(i,n) cin >> a[i];    
	ll ans = dp[0] = a[0];

	repb(i,1,n) {
		ll best = 0;
		rfor(j,i-1,0) {
			if(a[i] - a[j] == i-j) {
				best = max(best, dp[j]); break;
			} 
		} 
		dp[i] = a[i] + best;
		ans = max(ans, dp[i]); 
	}

	p1(ans);
}

void solve() {

	ll n, num, ans = 0; cin >> n;
	unordered_map<ll,ll> m;

	rep(i,n) {
		cin >> num;
		ll reduce = num-i;
		m[reduce] += num;
	}

	for(auto &it : m) {
		ans = max(ans, it.se);
	}

	p1(ans);
}


int main() {

	fastio;

    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

    //w(tc)
    	solve();
	
	return 0;
}