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

#define vb vector<bool>
#define vvb vector<vb>

void solve() {

    ll n, k; cin >> n >> k;
    vi a(n);
    rep(i,n) cin >> a[i];

    sort(a.begin(), a.end());

    vvb winningPosition(n+1, vb(k+1,false));

    repeb(i,1,n) {
    	repeb(j,1,k) {
    		if(a[i-1] <= j) {
    			winningPosition[i][j] = !winningPosition[i][j-a[i-1]]  or winningPosition[i-1][j];
    		} 
    		//	else {
    		// 	winningPosition[i][j] = winningPosition[i-1][j];
    		// }
    	}
    }

    // repe(i,n) p1(winningPosition[i]);

    (winningPosition[n][k]) ? p1("First") : p1("Second");
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