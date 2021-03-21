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
#define vd vector<double>
#define vvi vector<vi>
#define vvd vector<vd>
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

void solve1() {

	ll n; cin >> n;
	vd p(n+1);
	repeb(i,1,n) cin >> p[i];

	vvd dp(n+1, vd(n+1));

	// dp[h][c] -> getting exactly h heads from c available coins

	dp[0][0] = 1.0;

	repeb(i,1,n) dp[i][0] = 0.0; // i heads with no coins
	repeb(i,1,n) dp[0][i] = (1-p[i]) * dp[0][i-1]; // no heads

	repeb(c,1,n) {
		repeb(h,1,c) {
			double headsHere = p[c] * dp[h-1][c-1]; // get h-1 heads from c-1 coins and get heads at cth coin
			double tailsHere = (1-p[c]) * dp[h][c-1]; // get h heads from c-1 coins and get tails at cth coin
			dp[h][c] = headsHere + tailsHere;
		}
	}

	double ans = 0;
	repe(i,n) {
		ll heads = i, tails = n-i;
		if(heads > tails) ans += dp[heads][n];
	}

	cout << fixed << setprecision(10) << ans;
}

// O(n) space
void solve() {

	ll n; cin >> n;
	vd p(n+1);
	repeb(i,1,n) cin >> p[i];

	vd dp(n+1,0);
	dp[0] = 1.0;

	repeb(c,1,n) {
		rfor(h,c,0) {
			dp[h] = (dp[h] * (1-p[c])) + ((h == 0) ? 0 : dp[h-1]) * p[c];
		}
	}

	double ans = 0;
	repe(h,n) {
		ll t = n-h;
		if(h > t) ans += dp[h];
	}

	cout << fixed << setprecision(10) << ans;
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