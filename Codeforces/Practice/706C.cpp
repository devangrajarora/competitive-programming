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

#define INF 1e14+1

string rev(string s) {
	reverse(s.begin(), s.end());
	return s;
}

void solve() {

	ll n; cin >> n;
	vi c(n);
	rep(i,n) cin >> c[i];

	// dp[i][0] -> cost of sorting first i strings when ith string is not reversed    
	// dp[i][1] -> cost of sorting first i strings when ith string is reversed    

	ll prevVal = 0, currVal;
	ll prevValRev = c[0], currValRev;

	string prev, curr, currRev; cin >> prev;
	string prevRev = rev(prev);

	repb(i,1,n) {
		cin >> curr;
		currRev = rev(curr);

		ll op1 = (curr >= prev) ? prevVal : INF;
		ll op2 = (curr >= prevRev) ? prevValRev : INF;

		ll op3 = (currRev >= prev) ? prevVal + c[i] : INF;
		ll op4 = (currRev >= prevRev) ? prevValRev + c[i] : INF;

		currVal = min(op1, op2);
		currValRev = min(op3, op4);

		prevVal = currVal;
		prevValRev = currValRev;
		prev = curr;
		prevRev = currRev;
	}

	ll ans = min(currVal, currValRev);
	if(ans == INF) ans = -1;
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