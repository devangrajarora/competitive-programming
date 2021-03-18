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

bool comp(pii &a, pii &b) {
	return (a.fi != b.fi) ? a.fi > b.fi : a.se < b.se;
}

void solve() {

    ll n, m, q, w, val;
    cin >> n >> m >> q;

    vector<pii> v;
    rep(i,n) {
    	cin >> w >> val;
    	v.pb({val,w});
    }
    // p1(v);

    sort(v.begin(), v.end(), comp);

    // p1(v);

    vi x(m);
    rep(i,m) cin >> x[i];

    ll l, r;

    while(q--) {

    	cin >> l >> r;
    	l--, r--;
    	multiset<ll> s;

    	rep(j,m) {
    		if(j < l or j > r) {
    			s.insert(x[j]);
    		}
    	}

    	ll ans = 0, i = 0;

    	while(!s.empty() and i < n) {
    		ll val = v[i].fi, w = v[i].se;

    		auto it = s.lower_bound(w);
    		if(it != s.end()) {

    			s.erase(it);
    			ans += val;
    		} 

    		i++;
    	}

    	p1(ans);
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
    	solve();
	
	return 0;
}