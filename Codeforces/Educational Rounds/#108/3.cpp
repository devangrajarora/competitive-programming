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

void solve() {

    ll n; cin >> n;
    vi a[n];

    vi u(n), s(n);

    rep(i,n) {cin >> u[i]; u[i]--;};
    rep(i,n) {
        a[i].pb(0);
        cin >> s[i];
    }

    rep(i,n) {
        a[u[i]].pb(s[i]);
    }

    ll mx = 0;

    rep(i,n) {
        sort(a[i].begin(), a[i].end());
    }

    vi ans(n);

    rep(i,n) {

        ll sz = a[i].size()-1;
        if(sz == 0) continue;

        repb(j,1,a[i].size()) {
            a[i][j] += a[i][j-1];
        }

        for(int k = 1 ; k <= n ; k++) {
            ll options = sz/k*k;
            if(options == 0) break;
            ans[k-1] += a[i][sz] - a[i][sz-options];
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

    w(tc)
        solve();
    
    return 0;
}