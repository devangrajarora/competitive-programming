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

ll eegcd(ll A, ll B, ll &X, ll &Y) {

	if(B == 0) {
		X = 1;
		Y = 0;
		return A;
	}

	ll X1, Y1;
	ll g = eegcd(B,A%B,X1,Y1);
	X = Y1;
	Y = X1 - Y1 * (A/B);
	return g;
}

bool get_any_solution(ll a, ll b, ll c, ll &g, ll &X0, ll &Y0) {

    g = eegcd(abs(a),abs(b),X0,Y0);
    if(c%g) {
        return false;
    }

    X0 *= c/g;
    Y0 *= c/g;

    if(a < 0) X0 = -X0;
    if(b < 0) Y0 = -Y0;

    return true;
}

void solve() {

	while(true) {
		ll n, m, k, a;
		cin >> n >> m >> k >> a;
		if(n+m+k+a == 0) break;

    	// XA + YB = C
		ll A = m, B = -a, C = k-n+a, g, X0, Y0;

		bool op1 = get_any_solution(A,B,C,g,X0,Y0);
		ll ans = n+X0*m;

		while(true) {
			ll X1 = X0 + C*B/g;
			ll Y1 = Y0 - C*A/g;
			ll newAns = n+X1*m;
			if(newAns < ans and newAns > 0) {
				X0 = X1, Y0 = Y1;
				ans = newAns;
			} else break;
		}

		if(!op1) {
			p1("Impossible");
		} else {
			p1(ans);
		}
	}

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