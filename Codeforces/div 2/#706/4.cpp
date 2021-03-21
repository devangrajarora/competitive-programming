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

void solve() {

	ll n, mx = 0; 
	cin >> n;     
	vi a(n), v;
	rep(i,n) cin >> a[i];
	unordered_map<ll,ll> m;

	vi l(n,1), r(n,1);
	repb(i,1,n) if(a[i] > a[i-1]) l[i] = l[i-1] + 1, mx = max(mx,l[i]), m[l[i]]++;
	rfor(i,n-2,0) if(a[i] > a[i+1]) r[i] = r[i+1] + 1, mx = max(mx,r[i]), m[r[i]]++;

	ll ans = 0;
	if(m[mx] > 2 || m[mx] == 1) {
		p1(0);
		return;
	}

	repb(i,1,n-1) {
		if(l[i] > l[i-1] and r[i] > r[i+1]) {
			ll big = max(l[i],r[i]), small = min(l[i],r[i]);

			if(big == mx and small == mx and mx%2==1) {
				ans++;
				break;
			}		 
		}
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