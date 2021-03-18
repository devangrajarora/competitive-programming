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

int n;
string s, x;

bool takahashiCanWin(int idx, int rem, vvi &dp) {

	// if at the last index, remainder is 0 then number is divisible by 7 and Takahashi can win
	if(idx == n) return rem == 0;
	if(dp[idx][rem] != -1) return dp[idx][rem];
	bool one = takahashiCanWin(idx + 1, (rem*10) % 7, dp);
	bool two = takahashiCanWin(idx + 1, (rem*10 + (s[idx]-'0')) % 7, dp);

	return dp[idx][rem] = (x[idx] == 'A') ? one and two : one or two;
}

void solve() {

    cin >> n >> s >> x;

    // dp[i][j] -> current combination has j as remainder after going over first i numbers
    // at any index i, result depends on remainder of currNum % 7 at that point
    vvi dp(n, vi(7,-1));
    (takahashiCanWin(0,0, dp)) ? p0("Takahashi") : p0("Aoki"); 
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