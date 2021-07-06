#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD = 1000000007;
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

const int MAXM = 1e6;
vector<bool> sieve(MAXM+1,true);
vector<int> primes;

void precompute() {

    sieve[0] = sieve[1] = 0;
    for(ll i = 2 ; i <= MAXM ; i++) {
        if(sieve[i]) {
        	primes.push_back(i);
            for(ll j = i*i ; j <= MAXM ; j += i) {
                sieve[j] = 0;
            }
        }
    }
}

int primeFactors(int n) {
	int ans = 0;
	for(int prime : primes) {
		if(prime*prime > n) break;
		while(n%prime == 0) {
			n /= prime;
			ans++;
		}
	}

	if(n != 1) ans++;
	return ans;
}

void solve() {

    ll a, b, k; cin >> a >> b >> k;
	if(a < b) swap(a,b);

	if(a == 1 and b == 1) {
		p1("NO"); return;
	}

	if(k == 1) {
		if(a == b) p1("NO");
		else if(a%b) p1("NO");
		else p1("YES");
		return;
	}
    

    ll available = primeFactors(a) + primeFactors(b);
    // watch(available);

    if(available >= k) p1("YES");
    else p1("NO");
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    precompute();

    w(tc)
    	solve();
	
	return 0;
}