#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 100000000
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

ll dp[101][101][11][11];
ll K1, K2;

ll beautifulArrangements(ll n1, ll n2, ll k1, ll k2) {

	if(!n1 and !n2) return 1;
	if(dp[n1][n2][k1][k2] != -1) return dp[n1][n2][k1][k2];

	ll place1 = (n1 > 0 and k1 > 0) ? beautifulArrangements(n1-1,n2,k1-1,K2) : 0;
	ll place2 = (n2 > 0 and k2 > 0) ? beautifulArrangements(n1,n2-1,K1,k2-1) : 0;

	return dp[n1][n2][k1][k2] = (place1 + place2) % MOD;
} 

void solve() {

	memset(dp, -1, sizeof(dp));
    ll n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
    K1 = k1, K2 = k2;
    ll ans = beautifulArrangements(n1,n2,k1,k2);
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