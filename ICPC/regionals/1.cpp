#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s_int short int
#define ld long double
const int MOD = 1000000007;
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define endl "\n"
#define vi vector<short int>
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

const ll MAXM = 20;

struct SegmentTree {
	
    vi seg;
    ll sz, n;

    void init() {
        sz = 3ll*MAXM;
        this -> n = MAXM;
        seg.assign(sz,SHRT_MAX);
    }

    void build(vi &a, int pos, int l, int r) {
		if(l == r) {
			seg[pos] = a[l];
			return;
		}

		int mid = (l + r) / 2;
		build(a,2*pos+1,l,mid);
		build(a,2*pos+2,mid+1,r);
		seg[pos] = min(seg[2*pos+1],seg[2*pos+2]);
	}

	void build(vi &a) {
		build(a,0,0,n-1);
	}

    s_int query(ll pos, ll l, ll r, ll ql, ll qr) {
        if(ql > r or qr < l) return SHRT_MAX;
        if(ql <= l and r <= qr) return seg[pos];

        ll mid = (l + r)/2;
        s_int left = query(2*pos+1,l,mid,ql,qr);
        s_int right = query(2*pos+2,mid+1,r,ql,qr);
        return min(left,right);

    }

    s_int query(ll ql, ll qr) {
        return query(0,0,n-1,ql,qr);
    }

};

/*
	seg.init(n);
	seg.build(a);
	seg.update(idx,num);
	seg.query(ql,qr);
*/

SegmentTree seg;

void solve() {

    ll n, x; cin >> n >> x;
    if(x == 0 and n%2) {
    	p1("-1"); return;
    }

    if(x >= n) p1(1);
    else {
    	short int ans = seg.query(n-x,n);
    	p1(1+ans);
    }
}


short int fn(int n) {
	short int ans = 0, val = 1;
	for(int i = 0 ; i < 32 ; i++) {
		if(n&val) {
			ans += (i%2) ? 1 : 2; 
		}

		val *= 2;
	}

	return ans;
}

int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    seg.init();
    vi a(MAXM+1);

    for(int i = 0 ; i <= MAXM ; i++) {
    	a[i] = fn(i);
    }

    seg.build(a);
    // p1(a);

    int tc; cin >> tc;

    while(tc--)
    	solve();
	
	return 0;
}