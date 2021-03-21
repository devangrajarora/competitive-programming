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

void solve() {

	string a, b; cin >> a >> b;
	ll n = a.size(), m = b.size();
    vvi lcs(n+1, vi(m+1, 0));
    repeb(i,1,n) {
        repeb(j,1,m) {
			lcs[i][j] = (a[i-1] == b[j-1]) ? 1 + lcs[i-1][j-1] : max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    
    string ans = "";

    ll i = n, j = m;
    while(i > 0 and j > 0) {
        if(lcs[i][j] == lcs[i-1][j-1] + 1  and a[i-1] == b[j-1]) {
            ans = a[i-1] + ans;
            i--, j--;
        } else {
            (lcs[i][j-1] > lcs[i-1][j]) ? j-- : i--;
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