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

#define vp vector<pii>
#define vvp vector<vp>

void solve() {

	int n, m; cin >> n >> m;
	vvp dp(n, vp(m));

	vector<string> a(n);
	rep(i,n) cin >> a[i];

	dp[0][0] = {0,0};

	for(int j = 1 ; j < m ; j++) {
		int val = (a[0][j] == '+') ? 1 : -1;
		if(j%2) { // change first
			dp[0][j] = {dp[0][j-1].fi + val, dp[0][j-1].se};
		} else {
			dp[0][j] = {dp[0][j-1].fi, dp[0][j-1].se + val};
		}
	} 
	
	for(int i = 1 ; i < n ; i++) {
		int val = (a[i][0] == '+') ? 1 : -1;
		if(i%2) { // change first
			dp[i][0] = {dp[i-1][0].fi+val, dp[i-1][0].se};
		} else {
			dp[i][0] = {dp[i-1][0].fi, dp[i-1][0].se + val};
		}
	}

	for(int i = 1 ; i < n ; i++) {
		for(int j = 1 ; j < m ; j++) {
			bool changeFirst = (i + j) % 2;
			int val = (a[i][j] == '+') ? 1 : -1;
			ll newFi, newSe;
			pii up = dp[i-1][j], left = dp[i][j-1];
			if(changeFirst) {
				if(up.se - up.fi >= left.se - left.fi) {
					newFi = up.fi + val;
					newSe = up.se;
				} else {
					newFi = left.fi + val;
					newSe = left.se;
				}
			} else {
				if(up.fi - up.se >= left.fi - left.se) {
					newFi = up.fi;
					newSe = up.se + val;
				} else {
					newFi = left.fi ;
					newSe = left.se + val;
				}
			}

			dp[i][j] = {newFi,newSe};
		}
	}

	// rep(i,n) {
	// 	rep(j,m) {
	// 		p0(dp[i][j]);
	// 	} p1("");
	// }

	pii last = dp[n-1][m-1];
	// p1(last);

	if(last.fi == last.se) {
		p1("Draw");
	} else if(last.fi > last.se) {
		p1("Takahashi");
	} else {
		p1("Aoki");
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