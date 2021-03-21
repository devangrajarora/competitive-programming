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

ll CtOrderedPairs(ll N) 
{ 
    // Stores count of ordered pairs 
    ll res = 1; 
  
    // Calculate power of all 
    // prime factors of N 
    for (int i = 2; i * i <= N; i++) { 
  
        // Store the power of 
        // prime factors 
        ll countPower = 0; 
        while (N % i == 0) { 
            countPower++; 
            N /= i; 
        } 
  
        res = res * (2 * countPower 
                     + 1); 
    } 
  
    if (N > 1) { 
        res = res * (2 * 1 + 1); 
    } 
    return res; 
} 

ll c,d,x;


void solve() {

    cin >> c >> d >> x;
    ll gcd = 1, ans = 0;
    vi occured(c,0);
    // (x -gcd*d) / c

    while(true) {
    	ll num = x+(gcd*d), denom = c; 
    	if(num%denom==0) {
    		ll f = num/denom;
    		ll var = CtOrderedPairs(f);
    		ans += var;
    	} gcd++;
    	watch(gcd);
    	ll lcm = x+(gcd*d)/gcd;
    	if(!(x+(gcd*d)%gcd == 0 and lcm%gcd == 0)) break;
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