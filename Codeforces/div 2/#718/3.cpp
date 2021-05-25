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

ll n;

bool check(vvi &a, int r, int c) {
	if(r >= n or c < 0 or a[r][c] != 0) return false;
	else return true;
}

void print(vvi &a) {
	rep(i,n) {
		repe(j,i) {
			p0(a[i][j]);
		}p1("");
	}
}

void solve() {

	cin >> n;
    vvi a(n, vi(n));

    rep(i,n) cin >> a[i][i];

    rep(i,n) {
    	ll fill = a[i][i] - 1;
    	ll r = i, c = i;

    	while(fill) {
    		if(check(a,r,c-1)) {
    			a[r][c-1] = a[i][i];
    			c--; fill--;
    		} else if(check(a,r+1,c)) {
    			a[r+1][c] = a[i][i];
    			r++; fill--;
    		} else if(check(a,r,c+1)) {
    			a[r][c+1] = a[i][i];
    			c++; fill--;
    		} else {
    			p1(-1);
    			return;
    		}
    	}
    }

    print(a);
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