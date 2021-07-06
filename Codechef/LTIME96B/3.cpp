#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define vi vector<int>
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

#define MAXM 1e7+1
vector<int> prime(MAXM,1);
vector<int> psa(MAXM,0);

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

		int mid = (l + r) / 2;
		build(a,2*pos+1,l,mid);
		build(a,2*pos+2,mid+1,r);
		seg[pos] = seg[2*pos+1] + seg[2*pos+2];
	}

	void build(vi &a) {
		build(a,0,0,n-1);
	}

    ll query(ll pos, ll l, ll r, ll ql, ll qr) {
        if(ql > r or qr < l) return 0;
        if(ql <= l and r <= qr) return seg[pos];

        ll mid = (l + r)/2;
        ll left = query(2*pos+1,l,mid,ql,qr);
        ll right = query(2*pos+2,mid+1,r,ql,qr);
        return left + right;

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

void sieve() {

    prime[0] = prime[1] = 0;
    for(ll i = 2 ; i*i < MAXM ; i++) {
        if(prime[i]) {
            for(ll j = i*i ; j < MAXM ; j += i) {
                prime[j] = 0;
            }
        }
    }

}

SegmentTree seg;


void solve() {

    int n, ok = 0; cin >> n;

    if(n <= 3) {
    	p1(n-1); return;
    }

    // while(k--) {
    int ans = 1 + seg.query(n/2+1,n);
    // }
    
    // if(ok) ans++;
    p1(ans);

}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    sieve();
    seg.init(MAXM);
    seg.build(prime);
    
    w(tc)
    	solve();
	
	return 0;
}