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

const int MAXM = 3e5 + 5;

vi mp[MAXM];

ll cnt(int l, int r, ll num) {
    return upper_bound(mp[num].begin(), mp[num].end(), r) - lower_bound(mp[num].begin(), mp[num].end(), l); 
}

struct SegmentTree {
    
    vi seg;
    ll sz, n;

    void init(ll n) {
        sz = 4*n;
        this -> n = n;
        seg.assign(sz,0ll);
    }

    void build(vi &a, int pos, int l, int r) {
        if(l == r) {
            seg[pos] = a[l];
            return;
        }

        ll mid = (l + r) / 2;
        build(a,2*pos+1,l,mid);
        build(a,2*pos+2,mid+1,r);

        ll left = seg[2*pos+1], right = seg[2*pos+2];

        seg[pos] =  (cnt(l,r,left) > cnt(l,r,right)) ? left : right;
    }

    void build(vi &a) {
        build(a,0,0,n-1);
    }

    ll query(ll pos, ll l, ll r, ll ql, ll qr) {
        if(ql > r or qr < l) return 0;
        if(ql <= l and r <= qr) return cnt(ql,qr,seg[pos]);

        ll mid = (l + r)/2;
        ll lf = query(2*pos+1,l,mid,ql,qr);
        ll rf = query(2*pos+2,mid+1,r,ql,qr);
        return max(lf,rf);

    }

    ll query(ll ql, ll qr) {
        return query(0,0,n-1,ql,qr);
    }

};

/*
    seg.init(n);
    seg.build(a);
    seg.update(idx,num);
    seg.query(ql,qr);
*/

void solve() {

    ll n, q;
    cin >> n >> q;

    vi a(n);
    rep(i,n) {
        cin >> a[i];
        mp[a[i]].pb(i);
    }

    SegmentTree seg;
    seg.init(n);
    seg.build(a);

    while(q--) {
        ll l, r; cin >> l >> r;
        l--; r--;
        ll highestFreq = seg.query(l,r); // gets frequency of most frequent element
        ll total = r-l+1;
        ll rem = total-highestFreq;
        ll onepiece = 2*rem+1;

        bool superFrequent = (highestFreq > ceil(total/2.0)); // check if most frequent element is super frequent

        ll ans = (superFrequent) ? (total - onepiece + 1) : 1;
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