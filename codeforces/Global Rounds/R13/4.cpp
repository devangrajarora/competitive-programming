#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i <= b ; i++)
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

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

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

bool solve() {

    ll u, v;
    cin >> u >> v;
    if(u > v) return false;
    if(u == v) return true;

    vi uBits, vBits;

    ll cnt1 = 0, cnt2 = 0;

 	while(u) {
		cnt1++;
		if(u&1ll) uBits.pb(cnt1);
		u >>= 1;
	}

	while(v) {
		cnt2++;
		if(v&1ll) vBits.pb(cnt2);
		v >>= 1;
	}

	// p1(uBits);
	// p1(vBits);

	int i = 0, j = 0, n = uBits.size(), m = vBits.size();

	if(n < m) return false;
	while(i < m) {
		if(uBits[i] > vBits[i]) return false;
		i++;
	} 

    return true;
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    w(tc) {
    	(solve()) ? p1("YES") : p1("NO");
    }
	
	return 0;
}