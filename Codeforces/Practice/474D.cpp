#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
#define w(x) 

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

#define MAXM 100005
// #define MAXM 5

ll k;
vi noOfGoodStrings(MAXM, 1), psa(MAXM, 0);

void precompute() {
	repb(i,k,MAXM) {
			ll currIsWhite = noOfGoodStrings[i-k] % MOD; // i-k+1 ... i are fixed white
			ll currIsRed = noOfGoodStrings[i-1];
			noOfGoodStrings[i] = (currIsRed + currIsWhite) % MOD;
	}

	repb(i,1,MAXM) {
		psa[i] = psa[i-1] + noOfGoodStrings[i];
	}
}

void solve() {
	ll a,b; cin >> a >> b;
    ll ans = (psa[b] - psa[a-1]) % MOD;
    p1(ans);
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

    ll x; cin>>x>>k;
    precompute(); 
    while(x--)
    	solve();
	
	return 0;
}