#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define ll long long
#define ld long double
const int MOD = 1000000007;
#define fi first
#define se second
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define repe(i,n) for(int i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(int i = a ; i < b ; i++)
#define repeb(i,a,b) for(int i = a ; i <= b ; i++)
#define rfor(i,n,a) for(int i = n ; i >= a ; i--)
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define vvi vector<vi>
#define vc vector<char>
#define vvc vector<vc>
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

    void build(vi &a, int pos, int l, int r) {
        if(l == r) {
            seg[pos] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(a,2*pos+1,l,mid);
        build(a,2*pos+2,mid+1,r);
        seg[pos] = max(seg[2*pos+1],seg[2*pos+2]);
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
        return max(left,right);

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

    int n, m, k, minTime = INT_MAX; cin >> n >> m >> k;
    vi time(n*m+1);
    vi memo(n*m+1,-1);
    vvc a(n,vc(m));
    vvi psa(n+1, vi(m+1));
    int total = n*m;
    string result = "Draw";

    repeb(turn,1,total) {
    	int r,c;
    	cin >> r >> c;
    	r--, c--;
    	if(turn%2) {
    		a[r][c] = 'A';
    	} else {
    		a[r][c] = 'B';
    	}

    	time[r*m+c] = turn;
    }

    SegmentTree seg;
    seg.init(total);
    seg.build(time);


    repeb(i,1,n) {
    	repeb(j,1,m) {
    		psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + (a[i-1][j-1] == 'A');
    	}
    }

    repeb(i,k,n) {
    	repeb(j,k,m) {
    		int x1 = i-k+1, x2 = i, y1 = j-k+1, y2 = j;
    		int ans = psa[x2][y2] - psa[x1-1][y2] - psa[x2][y1-1] + psa[x1-1][y1-1];
    		int currTime = INT_MIN;

    		// watch(ans);
    		if(ans == k*k or ans == 0) {

                int col1 = y1-1, col2 = y2-1;
                repeb(row,x1-1,x2-1) {
                    int ql = row*m+col1, qr = row*m+col2, mx;
                    // p2(col1,col2);
                    // p1(row); p1("");
                    if(memo[ql] != -1) mx = memo[ql];
                    else {
                        mx = memo[ql] = seg.query(ql,qr);
                    }

                    currTime = max(currTime,mx);
                }

    			if(currTime < minTime) {
	    			minTime = currTime;
	    			result = (ans == k*k) ? "Alice" : "Bob";
	    		}
    		}


    	}
    }

    p1(result);
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