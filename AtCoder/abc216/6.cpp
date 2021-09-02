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
#define vi vector<int>
#define vvi vector<vi>
#define pii pair <int,int>
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

bool comp(pii &a, pii &b) {
	return a.first < b.first;
}

void solve() {

	int n; cin >> n;
    vector<pii> a(n);
    rep(i,n) cin >> a[i].first;
    rep(i,n) cin >> a[i].second;
    sort(a.begin(), a.end(), comp);

    int maxm = a[n-1].first, ans = 0;
    vi dp(maxm+1);
    dp[0] = 1;

	// dp(i,j) -> number of non empty subsequences in b[0...i] such that their sum is <= j
	rep(i,n) {
		int numA = a[i].first, numB = a[i].second;

		repe(j,numA-numB) {
			ans = (ans + dp[j]) % MOD;
		}

		rfor(j,maxm,0) {
			int exclude = dp[j];
			int include = (numB <= j) ? dp[j-numB] : 0;
			dp[j] = (include + (ll)exclude) % MOD;
		}
	}

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