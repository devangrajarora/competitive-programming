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

#define pr1 1000000007
#define pr2 1000000009

struct Soln {
	ll i;
	ll j;
	ll x;
	ll y;
};

void solve() {

    ll n, minEle = LLONG_MAX, minIdx; cin >> n;
    vi a(n);
    rep(i,n) {
    	cin >> a[i];
    	if(a[i] < minEle) {
    		minEle = a[i];
    		minIdx = i;
    	}
    }

    vector<Soln> ans;

    if(minIdx > 0 and __gcd(a[minIdx-1],a[minIdx]) != 1) {
    	ans.pb({minIdx,minIdx-1,a[minIdx],pr1});
    	a[minIdx-1] = pr1;
    }

	if(minIdx < n-1 and __gcd(a[minIdx+1],a[minIdx]) != 1) {
    	ans.pb({minIdx,minIdx+1,a[minIdx],pr1});
    	a[minIdx+1] = pr1;
    }

    repb(i,1,n) {
    	if(__gcd(a[i-1],a[i]) != 1) {
    		ans.pb({minIdx,i,a[minIdx],pr2});
    		a[i] = pr2;
    	}
    }

    p1(ans.size());
    for(auto &it : ans) {
    	cout << it.i+1 << " " << it.j+1 << " " << it.x << " " << it.y << "\n";
    }
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