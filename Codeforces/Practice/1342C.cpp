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

// for every k*lcm take first b elements

void solve1() {
	ll a, b, q; cin >> a >> b >> q;

	while(q--) {
		
		ll l, r; cin >> l >> r;
		repeb(i,l,r) {
			if(i%a%b == i%b%a) p1(i);
		}
	} 


}

void solve() {

	ll a, b, q; cin >> a >> b >> q;
	if(a > b) swap(a,b);
	ll lcm = (a*b)/__gcd(a,b);

	while(q--) {
		
		ll l, r; cin >> l >> r;
		ll left = l / lcm * lcm;
		ll right = r / lcm * lcm;
		ll val = 0;

		// watch(lcm);
		// p2(left, right);

		val += min(r-right+1,b);
		val += max(0ll, left+b-l);
		left += lcm;
		val += (right - left) / lcm * b;
		

		ll ans = (r-l+1) - val;
		p0(ans);
	} 

	p1("");
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