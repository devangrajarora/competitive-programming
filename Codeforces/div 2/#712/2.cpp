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

	ll n; cin>> n;
	string a, b; cin >> a >> b;

	if(a == b) {
		p1("YES");
	} else {

		vi idx;
		ll zero = 0, one = 0, z = 0, o = 0, same = 0, opp = 0, lastIdx = -1;

		rep(i,n) {

			(a[i] == '0') ? zero++ : one++;
			if(a[i] == b[i]) opp++;
			else same++;

			if(zero == one) {
				zero = one = 0;
				// p3(i,same,opp);
				if(same > 0 and opp > 0) {
					p1("NO");
					return;
				} 
				same = 0, opp = 0;
				lastIdx = i;
			} 
		}

		repb(i,lastIdx+1,n) {
			if(a[i] != b[i]) {
				p1("NO"); return;
			}
		}

		if(lastIdx == -1 or (same > 0 and opp > 0)) {
			p1("NO");
		} else {
			p1("YES");
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

	w(tc)
	solve();
	
	return 0;
}