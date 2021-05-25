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

	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;

	int dp[n+1][m+1][2];
	for(int i = 0 ; i <= n ; i++) 
		for(int j = 0 ; j <= m ; j++) 
			dp[i][j][0] = dp[i][j][1] = INT_MAX;

	/*
		dp[i][j][0] -> min cost for a[0...i-1] and b[0...j-1] where last char is a[i]
		dp[i][j][1] -> min cost for a[0...i-1] and b[0...j-1] where last char is b[j]
	*/


	dp[1][0][0] = 1;
	dp[0][1][1] = 1;


	for(int i = 0 ; i <= n ; i++) {
		for(int j = 0 ; j <= m ; j++) {
			if(i < n) { // last char is a[i]
				if(i > 0) dp[i+1][j][0] = min((a[i] != a[i-1]) + dp[i][j][0], dp[i+1][j][0]); // second last is a[i-1]
				if(j > 0) dp[i+1][j][0] = min((a[i] != b[j-1]) + dp[i][j][1], dp[i+1][j][0]); // second last is b[j-1]
			}

			if(j < m) { // last char is b[j]
				if(i > 0) dp[i][j+1][1] = min((b[j] != a[i-1]) + dp[i][j][0], dp[i][j+1][1]); // second last is a[i-1]
				if(j > 0) dp[i][j+1][1] = min((b[j] != b[j-1]) + dp[i][j][1], dp[i][j+1][1]); // second last is b[j-1]
			}
		}
	}

	ll ans = min(dp[n][m][0],dp[n][m][1]);
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