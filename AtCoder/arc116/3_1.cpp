#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define endl "\n"
#define vi vector<int>
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


// int func(int st, int n, vi &mem) {

// 	int ans = 0;
// 	if(st == -1) {
// 		repeb(i,1,m) {
// 			mem.pb(i);
// 			ans = ans + func(i,n-1,mem);
// 			mem.pop_back();
// 		}
// 		return ans;
// 	}

// 	if(st > m) return 0;
// 	// p2(st,n);
// 	if(n == 0) {
// 		p1(mem);
// 		return 1;
// 	}
// 	if(dp[n] != -1) return dp[n];
// 	int i = 1;
// 	while(st*i <= m) {
// 		mem.pb(st*i);
// 		ans = (ans + func(st*i,n-1,mem)) % MOD;
// 		i++;
// 		mem.pop_back();
// 	}
// 	dp[n] = ans;
// 	return dp[n];
// }

void solve() {

    int n,m; cin >> n >> m;
    vi dp(m+1,1), dp(m+1,0);
    int sum = m;

    rfor(i,n,0) {
    	// vi dp1(m+1,0);
    	dp1[1] = sum;
    	// sum;

    	for(int num = 2 ; num <= m/2+1 ; num++) {
	    	for(int j = 1 ; j*num <= m ; j++) {
	    		dp1[num] = (dp1[num] + dp[num*j]) % MOD;
	    	}
	    	
	    	sum = (sum + dp1[num]) % MOD;
	    } 
	    //p2(i,dp);
	    if(i > 0)
	    	repeb(j,1,m) dp[j] = dp1[j];
    }

    p1(dp[1]);
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