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

const int MAXM = 1e6+1;
vi fac(MAXM);
ll a,b,n;

bool good(ll num) {
	while(num) {
		int digit = num%10;
		if(digit != a and digit != b) return false;
		num /= 10;
	}

	return true;
}

ll modPower(ll num,ll r) {
    if(r==0) return 1;
    if(r==1) return num%MOD;
    ll ans=modPower(num,r/2)%MOD;
    if(r%2==0) {
        return (ans*ans)%MOD;
    } return (((ans*ans)%MOD)*num)%MOD;
}


ll inv(ll a) {
	return modPower(a,MOD-2);
}

void solve() {

	ll ans = 0; cin >> a >> b >> n;
	repe(i,n) {
		ll num = a*i + b*(n-i);
		if(good(num)) {
			ans = (ans + (fac[n] * inv(fac[i] * fac[n-i] % MOD) ) % MOD ) % MOD;
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

	fac[0] = fac[1] = 1;
	for(ll i = 2 ; i < MAXM ; i++) {
		fac[i] = (i * fac[i-1]) % MOD;
	}

	solve();
	
	return 0;
}