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

/*

(int weight -> n, bool covered)


k = 3, d = 2
						(4,false)
	(3,false)	 		(2,true) 		(1,true)
(2,false) (1,true) (0,true)
*/

void solve() {

	ll n, k, d;
	cin >> n >> k >> d;
	vvi dp(n+1, vi(2, 0));    
	dp[0][0] = 1;
	
	// dp[n][0] -> no of ways of getting sum n when we haven't encountered atleast one edge not less than d
	// dp[n][1] -> no of ways of getting sum n when we have encountered atleast one edge not less than d

	repeb(i,1,n) {
		repeb(j,1,k) {
			if(i-j < 0) break;
			if(j < d) { // current edge less than d
				dp[i][0] = (dp[i][0] + dp[i-j][0]) % MOD; 
				dp[i][1] = (dp[i][1] + dp[i-j][1]) % MOD;  
			} else { // current edge not less than d -> not dp[i] will have 1 as bool value coz we found a suitable edge
				dp[i][1] = (dp[i][1] + dp[i-j][0]) % MOD;  
				dp[i][1] = (dp[i][1] + dp[i-j][1]) % MOD;  
			}
		}
	}

	p1(dp[n][1]);
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