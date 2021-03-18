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

ll findMex(vi &a) {
	ll n = a.size();
	vi buckets(n+1,0);
	for(int i = 0 ; i < n ; i++) {
		ll num = a[i];
		if(num >= 0 and num <= n) {
			buckets[num] = 1;
		}
	}

	int i;
	for(i = 0 ; i <= n ; i++) {
		if(buckets[i] == 0) return i;
	} return i;
}


void solve() {

    ll n, k, MAX = INT_MIN;
    cin >> n >> k;
    vi a(n);
    unordered_map<ll,ll> m;

    rep(i,n) {
    	cin >> a[i];
    	MAX = max(MAX, a[i]);
    	m[a[i]]++;
    }

    if(k == 0) {
    	p1(n);
    	return;
    }

    ll MEX = findMex(a);

    // p2(MEX, MAX);

    if(MEX > MAX) {
    	p1(n+k);
    } else {
    	ll avg = ceil((MEX + MAX)/2.0);
    	if(m[avg]) p1(n);
    	else p1(n+1);
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