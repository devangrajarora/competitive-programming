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

struct SegmentTree {
	
    vi seg;
    ll sz, n;

    void init(ll n) {
        sz = 4*n;
        this -> n = n;
        seg.resize(sz);
    }

    void build(vi &a, ll pos, ll l, ll r) {
        if(l == r) {
            seg[pos] = 1;
            return;
        }

        ll mid = (l + r)/2;
        build(a,2*pos+1,l,mid);
        build(a,2*pos+2,mid+1,r);
        seg[pos] = seg[2*pos+1] + seg[2*pos+2];
    }

    void build(vi &a) {
        build(a,0,0,n-1);
    }

    void update(vi &a, ll idx, ll pos, ll l, ll r) {
        if(l == r) {
            seg[pos] = 0;
            a[idx] = 0;
            return;
        }

        ll mid = (l + r)/2;
        if(idx <= mid) update(a,idx,2*pos+1,l,mid);
        else update(a,idx,2*pos+2,mid+1,r);
        seg[pos] = seg[2*pos+1] + seg[2*pos+2];
    }

    void update(vi &a, ll idx) {
        update(a,idx,0,0,n-1);
    }

    ll query(ll k, ll pos, ll l, ll r) {
        if(l == r and k == 1) {
            return l;
        }

        ll mid = (l + r)/2;
        ll rightOnes = seg[2*pos+2];
        if(rightOnes >= k) return query(k,2*pos+2,mid+1,r);
        else return query(k-rightOnes,2*pos+1,l,mid);

    }

    ll query(ll k) {
        return query(k,0,0,n-1);
    }

};

void solve() {

	ll n; cin >> n;
    SegmentTree seg;
    seg.init(n);

    vi a(n,1);
    seg.build(a);

    vi onesFromRight(n), ans;
    rep(i,n) {
        cin >> onesFromRight[i];
        onesFromRight[i]++;
    }

    rfor(i,n-1,0) {
        ll pos = seg.query(onesFromRight[i]);
        ans.pb(pos+1);
        seg.update(a,pos);
    }

    reverse(ans.begin(), ans.end());
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