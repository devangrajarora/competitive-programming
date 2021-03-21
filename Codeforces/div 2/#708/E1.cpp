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

#define MAXN   10000001 
  
// stores smallest prime factor for every number 
ll spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 	
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
        spf[i] = i; 

    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 

ll getFactorization(ll x) 
{ 
    ll ans = 1, cnt = 0;
    unordered_map<ll,ll> m;
    while (x != 1) 
    { 
        m[spf[x]]++; 
        x = x / spf[x]; 

    } 

    for(auto &it : m) {
    	if(it.se % 2) {
    		ans *= it.fi;
    	}
    }

    return ans; 
} 
  

void solve() {

    ll n, k, num;
    cin >> n >> k;
    vi a(n,0);
    rep(i,n) {
    	cin >> num;
    	a[i] = getFactorization(num);
    }

    ll l = 0, h = 0, cuts = 0;
    unordered_map<ll,ll> m;

    while(h < n) {
    	m[a[h]]++;
    	if(m[a[h]] > 1) {
    		// p2("CUT:",h);
    		cuts++;
    		while(l < h) {
    			m[a[l]]--;
    			l++;
    		}
    	} h++;
    }

    // p1(a);
    p1(cuts+1);
}


int main()
{
	fastio;
	sieve();
    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

    w(tc)
    	solve();
	
	return 0;
}