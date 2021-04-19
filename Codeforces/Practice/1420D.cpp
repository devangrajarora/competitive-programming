#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 998244353
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define popb pop_back()
#define endl "\n"
#define vi vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair < long long, long long >
typedef priority_queue<ll, vector<ll>, greater<ll>> minheap;
typedef priority_queue<ll> maxheap;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
#define sortv(v) sort(v.begin(),v.end())
#define rsortv(v) sort(v.begin(),v.end(), greater<>());
#define sortby(v,prop) sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop < rhs.prop; });
#define rsortby(v,prop) sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop > rhs.prop; });

ll modPower(ll num,ll r){
	if(r==0) return 1;
	if(r==1) return num%MOD;
	ll ans=modPower(num,r/2)%MOD;
	if(r%2==0) {
		return (ans*ans)%MOD;
	} return (((ans*ans)%MOD)*num)%MOD;
}

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
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
        {
            if(!first)
                os << ", ";
            os << *iii;
            first = false;
        }
        return os << "]";
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

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code   


ll inv(ll a) {
    return modPower(a,MOD-2);
}

void factorial(ll *fact, ll * factorialNumInverse, ll n) 
{ 
    fact[0] = 1; factorialNumInverse[0] = inv(fact[0]);
  
    for (int i = 1; i <= n; i++) { 
        fact[i] = (fact[i - 1] * i) % MOD;
        factorialNumInverse[i] = inv(fact[i]);
    } 
} 
  
// Function to return nCr % MOD in O(1) time 
ll nCr(ll n, ll r, ll *fact, ll *factorialNumInverse) 
{ 
    // n C r = n!*inverse(r!)*inverse((n-r)!) 
    ll ans = (((fact[n] * factorialNumInverse[r]) % MOD) * factorialNumInverse[n-r]) % MOD; 
    return ans; 
} 
  


bool comp(pii &a, pii &b) {
	if(a.fi == b.fi) return a.se > b.se;
	return a.fi < b.fi;
}


void solve() {

	ll n, k;
	cin >> n >> k;

	ll factorialNumInverse[n+1]; 
	ll fact[n+1]; 
    factorial(fact, factorialNumInverse, n); 

	vector<pii> a;

	rep(i,n) {
		ll l, r;
		cin >> l >> r;
		a.pb({l,1});
		a.pb({r,-1});
	}

	sort(a.begin(), a.end(), comp);

	vi peaks;
	ll sum = 0;
	for(auto it : a) {
		sum += it.se;
		peaks.pb(sum);
	}

	// p1(peaks);

	ll sz = peaks.size(), ans = 0, prev = -1;
	bool init  = false;
	rep(i,sz-1) {
		if(peaks[i] == k && !init) {
			init = true;
			ans = 1;
		} else if(init) {
			if(peaks[i] >= k && peaks[i] > peaks[i-1]) {

				ll mul;
				if(prev == -1) {
					mul = nCr(peaks[i]-1,k-1, fact, factorialNumInverse);
				} else {
					mul = (mul * (peaks[i]-1)) % MOD;
				}

				ans = (ans + mul)%MOD;
			} else {
				prev = -1;
			}
		}

		// p0(ans);
	}
	// cout << "\n";
	p1(ans);
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

	solve();
	return 0;
}