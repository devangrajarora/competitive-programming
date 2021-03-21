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
rotating dp state
Since capacity can be vey high, we consider N and price to be out parameters for DP as their values are relatively lower
dp[i][v] -> minimum weight which can give the  value v from first i items
for (i,v), if current item is not included then, dp[i][v] = dp[i-1][v]
else if value[i] does not exceed v, we can choose to include ith item, so another option would be dp[i][v] = dp[i-1][v - value[i]] + weight[i]
choose the one which gives minimum weight
*/

// O(n) space
void solve1() {

    ll N, W;
    cin >> N >> W;
    ll maxVal = 0;

    vi val(N), weight(N);
    rep(i,N) {
        cin >> weight[i] >> val[i];
        maxVal += val[i];
    }

    vi dp(maxVal+1, INT_MAX); // initialise with case where N = 0 ie no items
    dp[0] = 0; // target value is 0

    repeb(i,1,N) {
    	rfor(v,maxVal,1) {
            ll dontInclude = dp[v], include = INT_MAX;
            if(v >= val[i-1]) include = dp[v - val[i-1]] + weight[i-1];
            dp[v] = min(include, dontInclude);
        }
    }

    ll j = maxVal;
    while(j >= 0) {
        if(dp[j] <= W) {
            p1(j);
            return;
        }
        j--;
    }
}

// O(n^2) space
void solve2() {
 
    ll N, W;
    cin >> N >> W;
    ll maxVal = 0;
 
    vi val(N), weight(N);
    rep(i,N) {
        cin >> weight[i] >> val[i];
        maxVal += val[i];
    }
 
    vvi dp(N+1, vi(maxVal+1, INT_MAX));
 
    repe(v,maxVal) dp[0][v] = INT_MAX;
    repe(i,N) dp[i][0] = 0;
 
    repeb(i,1,N) {
        repeb(v,1,maxVal) {
            ll dontInclude = dp[i-1][v], include = INT_MAX;
            if(v >= val[i-1]) include = dp[i-1][v - val[i-1]] + weight[i-1];
            dp[i][v] = min(include, dontInclude);
            
        }
    }
 
    ll j = maxVal;
    while(j >= 0) {
        if(dp[N][j] <= W) {
            p1(j);
            return;
        }
        j--;
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
    solve1();

    return 0;
}