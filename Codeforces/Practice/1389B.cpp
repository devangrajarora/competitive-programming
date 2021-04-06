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

ll n;

// recursive
// ll move(vi &a, ll i, ll k, ll z, bool leftAllowed) {
// 	if(i == n) return 0;
// 	if(k == 0) return a[i];

// 	ll score = a[i];
// 	ll moveLeft = (i > 0 and z > 0 and leftAllowed) ? move(a,i-1,k-1,z-1,false) : 0; 
// 	ll moveRight = (i < n) ? move(a,i+1,k-1,z,true) : 0;
// 	return score + max(moveLeft, moveRight); 
// }

void solve() {

	ll z, k, prev = 0, bp = 0, ans = 0; cin >> n >> k >> z;
	vi a(n), psa(n), bestPair(n);
	rep(i,n) cin >> a[i];

	rep(i,n) {
		psa[i] = prev + a[i];
		bp = max(bp, (i < n-1) ? a[i]+a[i+1] : 0);
		bestPair[i] = bp;
		prev = psa[i];
	}

    // t pairs or (right,left) moves; 0 <= t <= z 
    // k- 2t right moves
    // currAns = a[0 ... k-2t] + t * max(a[i] + a[i+1])

	repe(t,z) {
		if(2*t > k) continue;
		ll currAns = psa[k-2*t] + t*bestPair[k-2*t];
		ans = max(ans, currAns);
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

	w(tc)
		solve();
	
	return 0;
}