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

void buildTree(vi &a, vi &seg, int l, int r, int pos) {

	if(l == r) {
		seg[pos] = a[l];
	} else {

		int mid = l + (r-l)/2;
		buildTree(a,seg,l,mid,2*pos+1);
		buildTree(a,seg,mid+1,r,2*pos+2);
		seg[pos] = seg[2*pos+1] | seg[2*pos+2];
	}
}

int query(vi &seg, int l, int r, int pos, int ql, int qr) {

	if(ql > r || qr < l) { // no overlap
		return 0;
	}else if(ql <= l && qr >= r) { // total overlap
		return seg[pos];
	} else {

		int mid = l + (r-l)/2;
		int left = query(seg,l,mid,2*pos+1,ql,qr);
		int right = query(seg,mid+1,r,2*pos+2,ql,qr);
		return left | right;
	}
}

void update(vi &seg, vi &a, int index, int val, int l, int r, int pos) {

	if(l == r) {
		a[index] = val;
		seg[pos] = val;
	} else {
		int mid = l + (r-l)/2;
		
		if(l <= index && index <= mid) {
			update(seg,a,index,val,l,mid,2*pos+1);
		} else {
			update(seg,a,index,val,mid+1,r,2*pos+2);
		}

		seg[pos] = seg[2*pos+1] | seg[2*pos+2];
	}

}

void solve() {

	ll n, q, x, v;
	cin >> n >> q;

	vi a(n), segOR(4*n);
    
    rep(i,n) cin >> a[i];

	buildTree(a,segOR,0,n-1,0);
	cout << segOR[0] << "\n";

	rep(i,q) {
		cin >> x >> v;
		x--;
		update(segOR,a,x,v,0,n-1,0);
		cout << segOR[0] << "\n";
	}

}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    w(tc) {
    	solve();
    }
	
	return 0;
}