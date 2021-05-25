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

#define FLUSH fflush(stdout)

map<pii, ll> m;

ll query(ll l, ll r) {
    if(m.find({l,r}) != m.end()) {
        return m[{l,r}];
    }

    ll ones;
    cout << "? " << l << " " << r << "\n";
    FLUSH;
    cin >> ones;
    return ones;
}

void func(ll l, ll r, ll k) {
    if(l > r) return;
    if(l == r and k == 1) {
        cout << "! " << l << "\n";
        FLUSH;
        return;
    }

    ll mid = (l + r) / 2, zeroes, ones;
    ones = query(l,mid);
    FLUSH;
    zeroes = mid-l+1 - ones;
    if(zeroes >= k) {
        func(l,mid,k);
        m[{l,mid}] = ones+1;
    } else {
        func(mid+1,r,k-zeroes);
    }
}

void solve() {

    FLUSH;
    ll n, t; cin >> n >> t;
    while(t--) {
        FLUSH;
        ll k; cin >> k;
        func(1,n,k);
    }

}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    solve();
    
    return 0;
}