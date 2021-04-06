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

// 0,1,2,3 -> D,A,B,C
// moveTo(0,N) =  sum ( moveTo([1,2,3], N-1) )

// o(4*N) space

ll moveTo(int dest, int n, vvi &dp) {
	if(n == 0) return dest == 0;
	if(dp[dest][n] != -1) return dp[dest][n];
	ll ans = 0;
	rep(i,4) {
		if(i == dest) continue;
		ans = (ans + moveTo(i, n-1, dp)) % MOD;
	}

	return dp[dest][n] = ans;
}

// O(1) space

void solve() {

    int n; cin >> n;
    int waysToD = 1, waysToA = 0, waysToB = 0, waysToC = 0;
    repeb(i,1,n) {
    	int nextWaysToD = ((waysToA + waysToB) % MOD + waysToC) % MOD;
    	int nextWaysToA = ((waysToD + waysToB) % MOD + waysToC) % MOD;
    	int nextWaysToB = ((waysToA + waysToD) % MOD + waysToC) % MOD;
    	int nextWaysToC = ((waysToA + waysToB) % MOD + waysToD) % MOD;

    	waysToD = nextWaysToD, waysToA = nextWaysToA, waysToB = nextWaysToB, waysToC = nextWaysToC;
    }

    p1(waysToD);
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