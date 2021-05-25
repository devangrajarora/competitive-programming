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
#define vi vector<int>
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

	template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
        {
            if(!first)
                os << ", ";
            os << *iii ;
            first = false;
        }
        return os << "]";
    }

    
/*-------------------------------------------------*/

// read once, read again, think, code

const int MAXM = 1e5+1;
const int LOG = 18;

int up[MAXM][LOG+1];
vi adj[MAXM+1];

void binaryLifting(ll curr, ll parent) {
	up[curr][0] = parent;
	for(int i = 1 ; i <= LOG ; i++) {
		if(up[curr][i-1] != -1) {
			up[curr][i] = up[up[curr][i-1]][i-1];
		} else {
			up[curr][i] = -1;
		}
	}

	for(auto &child : adj[curr]) {
		binaryLifting(child, curr);
	}
}

int query(int l, int r) {

	ll ans = 0;
	for(int i = LOG ; i >= 0 ; i--) {
		if(up[l][i] != -1 and  r >= up[l][i]) {
			ans += (1<<i);
			l = up[l][i];
		}
	}

	// at this point L <= R, and closest it can be
	// 1 added to give subrange from [lastL .. R]
	return 1+ans;
}


void solve() {

    ll n, q, l, r;
    cin >> n >> q;

    vi a(n+1), go(n+2);
    go[n+1] = n+1;

    repeb(i,1,n) cin >> a[i];

    unordered_map<ll, ll> m;
    m.reserve(1<<10);
    m.max_load_factor(0.25);

    rfor(i,n,1) {
    	ll num = a[i], nearestCommonFactor = go[i+1], j = 2, sq = sqrt(num);
    	while(j <= sq) {

    		if(num % j == 0) {
    			if(m.find(j) != m.end()) {
    				nearestCommonFactor = min(nearestCommonFactor, m[j]);
    			}

    			m[j] = i;

    			while(num%j == 0) num /= j;
    		}

    		j++;
    	} 

    	if(num > 1) {
    		if(m.find(num) != m.end()) {
    			nearestCommonFactor = min(nearestCommonFactor, m[num]);
    		}
    		m[num] = i;
    	}

    	go[i] = nearestCommonFactor;
    }

    // every edge in this graph represents a subrange of coprime numbers
    repeb(i,1,n) {
    	adj[go[i]].pb(i);
    }

    binaryLifting(n+1,-1);

    while(q--) {
    	cin >> l >>	 r;
    	p1(query(l,r));
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