#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD = 998244353;
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

const int MAXM = 1e6+1;
vi divisors(MAXM,1);

/*

total -> 1...2*n
Observation: any pair which is not nested with each other must have equal length

two cases for placing a pair [1,x]

1. 	if x <= n, every pair will have one point outside [1,x], thus no pair is nested ie every pair is of same length.
	number of such pairs is number of divisors of n 

	total possiblities = divisors(n) 

2.	if x > n, last pair will be [2n-x+1, 2n]

	Space from [2n-x+2,x-1] is free
	-> (x-1) - (2n-x+1) + 1 points free
	-> 2x-2n-2 points free
	-> x-n-1 pairs

	x ranges from n+1 ... 2n
	x-n-1 ranges from 0 ... n-1

	total possiblities = dp[0] + ... + dp[n-1]

ans = divisors(n) + (dp[0] + ... + dp[n-1])

*/

void solve() {

    ll N, runningSum = 1; cin >> N;
    vi dp(N+1);
    dp[0] = dp[1] = 1;

    for(ll i = 2 ; i < MAXM ; i++) {
    	for(ll j = i ; j < MAXM ; j += i) {
    		divisors[j]++;
    	}
    }

    for(ll n = 2 ; n <= N ; n++) {
    	dp[n] = (runningSum + divisors[n]) % MOD;
    	runningSum = (runningSum + dp[n]) % MOD;
    }

    p1(dp[N]);
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