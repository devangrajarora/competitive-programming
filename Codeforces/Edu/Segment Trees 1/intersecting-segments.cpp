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
        seg.assign(sz,0ll);
    }

    void update(ll idx, ll num, ll pos, ll l, ll r) {
        if(l == r) {
            seg[pos] = num;
            return;
        }

        ll mid = (l + r)/2;
        if(idx <= mid) update(idx,num,2*pos+1,l,mid);
        else update(idx,num,2*pos+2,mid+1,r);
        seg[pos] = seg[2*pos+1] + seg[2*pos+2];
    }

    void update(ll idx, ll num) {
        update(idx,num,0,0,n-1);
    }

    ll query(ll pos, ll l, ll r, ll ql, ll qr) {
        if(ql > r or qr < l) return 0;
        if(ql <= l and r <= qr) return seg[pos];

        ll mid = (l + r)/2;
        return query(2*pos+1,l,mid,ql,qr) + query(2*pos+2,mid+1,r,ql,qr);

    }

    ll query(ll ql, ll qr) {
        return query(0,0,n-1,ql,qr);
    }

};

void solve() {

    ll n, num; cin >> n;

    SegmentTree seg;
    seg.init(2*n);

    vi left(n+1,-1), ans(n+1);
    vi a(2*n);
    rep(i,2*n) cin >> a[i];

    rep(i,2*n) {
    	num = a[i];
    	if(left[num] == -1) {
    		left[num] = i;
            seg.update(i,1);
    	} else {
            seg.update(left[num],0);
            ans[num] = seg.query(left[num],i);
    	}
    }

    seg.init(2*n);
    vi right(n+1,-1);

    rfor(i,2*n-1,0) {
        num = a[i];
        if(right[num] == -1) {
            right[num] = i;
            seg.update(i,1);
        } else {
            seg.update(right[num],0);
            ans[num] += seg.query(i,right[num]);
        }
    }

    repeb(i,1,n) p0(ans[i]);
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