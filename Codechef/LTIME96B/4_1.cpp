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
 
struct Node {
	ll maxm;
	ll prefix;
	ll suffix;
	ll sumAll;
};
 
struct SegmentTree {
 
	vector<Node> seg;
	int size;
 
	void init(int n) {
		size = 4*n;
		seg.assign(size,{0,0,0,0});
	}
 
	void build(vi &a, int pos, int l, int r) {
		if(l == r) {
			seg[pos] = {a[l],a[l],a[l],a[l]}; return;
		}
 
		int mid = (l + r) / 2;
		build(a,2*pos+1,l,mid);
		build(a,2*pos+2,mid+1,r);
		Node left = seg[2*pos+1], right = seg[2*pos+2]; 
		
		ll sumAll = left.sumAll + right.sumAll;
		ll prefix = max(left.prefix, left.sumAll + right.prefix);
		ll suffix = max(right.suffix, left.suffix + right.sumAll);
		ll maxm = max({left.maxm, right.maxm, left.suffix + right.prefix});
		seg[pos] = {maxm, prefix, suffix, sumAll};
	}
 
	void build(vi &a, int n) {
		build(a,0,0,n-1);
	}

	Node query(ll pos, ll l, ll r, ll ql, ll qr) {
        if(ql > r or qr < l) return {INT_MIN,INT_MIN,INT_MIN,INT_MIN}; // no overlap
        if(ql <= l and r <= qr) return seg[pos];

        ll mid = (l + r)/2;
        Node left = query(2*pos+1,l,mid,ql,qr);
        Node right = query(2*pos+2,mid+1,r,ql,qr);
        ll sumAll = left.sumAll + right.sumAll;
		ll prefix = max(left.prefix, left.sumAll + right.prefix);
		ll suffix = max(right.suffix, left.suffix + right.sumAll);
		ll maxm = max({left.maxm, right.maxm, left.suffix + right.prefix});
        return {maxm, prefix, suffix, sumAll};

    }
 
	ll query(int ql, int qr, int n) {
		return query(0,0,n-1,ql,qr).maxm;
	}
};

void k1(ll n, ll k, vi &a) {

    vector<ll> dp(n);
    dp[0] = a[0];
    ll ans = dp[0];
    
    for(int i = 1 ; i < n ; i++) {
        dp[i] = a[i] + max(dp[i-1],0ll);
        ans = max(ans, dp[i]);
    }

    p1(ans);
}
 
void solve() {
 
	int n, k; cin >> n >> k;
	vi a(n);
	rep(i,n) cin >> a[i];
 	
 	if(k == 1) {
		k1(n,k,a);
		return;
	}
	
	SegmentTree seg;
 
	seg.init(n);
	seg.build(a,n);
	
	ll ans = LLONG_MIN;

	repeb(i,0,n-2) {
 
		ll left = seg.query(0,i,n);
		ll right = seg.query(i+1,n-1,n);
		ll curr = left + 2*right;
		ans = max(ans,curr);
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