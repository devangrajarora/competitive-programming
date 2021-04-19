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

void buildTree(vi &a, vi &seg, int l, int r, int pos) {

	if(l == r) {
		seg[pos] = l;
	} else {

		int mid = l + (r-l)/2;
		buildTree(a,seg,l,mid,2*pos+1);
		buildTree(a,seg,mid+1,r,2*pos+2);
		ll minIdx = (a[seg[2*pos+1]] < a[seg[2*pos+2]]) ? seg[2*pos+1] : seg[2*pos+2]; 
		seg[pos] = minIdx;
	}
}

int query(vi &seg, int l, int r, int pos, int ql, int qr, vi &a) {

	if(ql > r || qr < l) { // no overlap
		return -1;
	}else if(ql <= l && qr >= r) { // total overlap
		return seg[pos];
	} else {

		int mid = l + (r-l)/2;
		int left = query(seg,l,mid,2*pos+1,ql,qr,a);
		int right = query(seg,mid+1,r,2*pos+2,ql,qr,a);

		if(left == -1 and right == -1) return -1;
		else if(left == -1) return right;
		else if(right == -1) return left;
		else return (a[left] < a[right]) ? left : right;
	}
}

void findMin(vi &a, ll l, ll r, ll &ans, vi &seg, ll n) {

	if(l > r) return;

	ll minIdx = query(seg,0,n-1,0,l,r,a);
	ll minEle = a[minIdx];
	ans += (minIdx-l+1) * (r-minIdx+1) * minEle;

	findMin(a,l,minIdx-1,ans,seg,n);
	findMin(a,minIdx+1,r,ans,seg,n);
}

void solve() {

    ll n; cin >> n;
    vi a(n), seg(4*n);
    rep(i,n) cin >> a[i];

    buildTree(a,seg,0,n-1,0);
    
    ll ans = 0;

    findMin(a,0,n-1,ans,seg,n);
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