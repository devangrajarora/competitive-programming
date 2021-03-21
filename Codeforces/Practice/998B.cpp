#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
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

int n, ans = 0;

void backtrack(vi &a, int st, int odd, int even, int cuts, int b) {
	if(st == n) {
		// if(b >= 0) {
			// p1("hi");
			ans = max(ans,cuts-1);
			return;
	}

	if(b < 0) return;

	for(int i = st ; i < n ; i++) {
		(a[i]%2) ? odd++ : even++;
		if(odd == even) {
			// p4(st,i, odd, even);
			backtrack(a,i+1,0,0,cuts+1,b-abs(a[i] - a[i+1]));
		}
	}
}

void solve() {

	int b, odd = 0, even = 0, sum = 0;
    cin >> n >> b; 
    vi a(n,0);
    rep(i,n) {
    	cin >> a[i];
    }

    vi v;

    rep(i,n) {
    	(a[i]%2) ? odd++ : even++;
    	if(odd == even and i != n-1) {
    		int diff = abs(a[i] - a[i+1]); 
    		sum += diff;
    		v.pb(diff);
    		odd = 0, even = 0;
    	}
    }

    sort(v.rbegin(), v.rend());
    int ans = v.size(), i = 0, m = v.size();
    while(i < m and sum > b) {
    	sum -= v[i];
    	i++;
    	ans--;
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

    //w(tc)
    	solve();
	
	return 0;
}