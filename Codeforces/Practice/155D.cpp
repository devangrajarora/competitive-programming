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

void solve() {

	ll n, m, idx; cin >> n >> m;
	char op;
	unordered_map<int,int> primeFactorMap;
	vector<int> primeFactors[n+1];

	// 
	for(ll i = 2 ; i <= n ; i++) {
		if(primeFactors[i].size() == 0) {
			for(ll j = i ; j <= n ; j += i) {
				primeFactors[j].pb(i);
			}
		}
	}

	vector<bool> activated(n+1, false);

	rep(_,m) {
		cin >> op >> idx;
		if(op == '+') {

			if(activated[idx]) {
				p1("Already on");
				continue;
			}

			int ok = 1;
			// checking recurring prime factors
			for(auto &factor : primeFactors[idx]) {
				if(primeFactorMap[factor] > 0) {
					p2("Conflict with", primeFactorMap[factor]);
					ok = 0;
					break;
				}
			}

			

			if(!ok) continue;
			p1("Success");
			activated[idx] = 1;
			// adding prime factors of added collider to map 
			for(auto &factor : primeFactors[idx]) {
				primeFactorMap[factor] = idx;
			}


		} else {
			if(activated[idx]) {
				activated[idx] = 0;

				// removing prime factors of removed collider from map 
				for(auto &factor : primeFactors[idx]) {
					primeFactorMap[factor] = 0;
				}

				p1("Success");
			
			} else {
				p1("Already off");
			}
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