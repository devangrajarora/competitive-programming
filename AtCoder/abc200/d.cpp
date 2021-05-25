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

void solve() {

	int n; cin >> n;
	vi a(n);
	rep(i,n) cin >> a[i];
	n = min(n,8);    
	ll en = 1 << n;
	unordered_map<int, vi> m;
	m.reserve(1<<10);
	m.max_load_factor(0.25);

	for(int mask = 1 ; mask < en ; mask++) {
		int cmask = mask, sum = 0, i = 0;
		vi curr;
		while(cmask) {
			if(cmask&1) {
				curr.pb(i+1);
				sum = (sum + a[i]) % 200;
			}

			cmask >>= 1;
			i++;
		}

		if(m.find(sum) != m.end()) {
			p1("Yes");
			p0(m[sum].size()); p1(m[sum]);
			p0(curr.size()); p1(curr);
			return;
		} else {
			// cout << "INSERT: " << sum << ": " << curr << "\n"; 
			m[sum] = curr;
		}
	}

	p1("No");
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