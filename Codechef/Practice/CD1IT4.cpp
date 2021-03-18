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

	ll n,m,p;
	cin >> n >> m >> p;
	vvi a(n, vi(m,0));
	rep(i,p) {
		ll x,y;
		cin >> x >> y;
		a[x-1][y-1] = -1;
	} 

	if(a[0][0] == -1 or a[n-1][m-1] == -1) {
		p1(0);
		return;
	}

	rep(i,n) {
		if(a[i][0] == 0) a[i][0] = 1;
		else break;
	}

	repb(j,1,m) {
		if(a[0][j] == 0) a[0][j] = 1;
		else break;
	}

	repb(i,1,n) {
		repb(j,1,m) {
			if(a[i][j] == -1) continue;
			a[i][j] = (a[i][j] + max(a[i-1][j], 0ll))%MOD;
			a[i][j] = (a[i][j] + max(a[i][j-1], 0ll))%MOD;
		}
	}

	// rep(i,n) {
	// 	p1(a[i]);

	// }

	p1(a[n-1][m-1]);
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