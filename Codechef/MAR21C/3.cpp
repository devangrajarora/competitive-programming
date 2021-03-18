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

	ll n, e, h, a, b, c, ans = LLONG_MAX;
	cin >> n >> e >> h >> a >> b >> c;

	// x omlettes, y milshakes, z cakes 

	// for constant z, we try to maximise the number of items bw cake and milkshakes which have lesser cost 
	repe(z,n) {

		ll N = n;
		ll E = e-z, H = h-z;

		if(E < 0 or H < 0) continue;

		ll maxOmlettes = min(N-z,E/2);
		ll milkshakes = N-z-maxOmlettes;

		ll maxMilkshakes = min(N-z,H/3);
		ll omlettes = N-z-maxMilkshakes;

		ll val = LLONG_MAX;

		if(3*milkshakes<=H and 2*maxOmlettes<=E and a*maxOmlettes+b*milkshakes < val) {
			val = a*maxOmlettes+b*milkshakes;
		} 

		if(2*omlettes<=E and 3*maxMilkshakes<=H and b*maxMilkshakes+a*omlettes < val) {
			val =  b*maxMilkshakes+a*omlettes;
		}

		if(val != LLONG_MAX) {
			ans = min(ans,c*z + val);
		}
	}

	if(ans == LLONG_MAX) ans = -1;
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