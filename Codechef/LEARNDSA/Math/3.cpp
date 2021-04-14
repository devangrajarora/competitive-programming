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

#define MAXM 201
vector<bool> prime(MAXM,true);
unordered_map<ll,ll> m;

void sieve() {

    prime[0] = prime[1] = 0;
    for(ll i = 2 ; i*i <= MAXM ; i++) {
        if(prime[i]) {
            for(ll j = i*i ; j < MAXM ; j += i) {
                prime[j] = 0;
            }
        }
    }
}

void semiprimes() {
    repb(i,2,MAXM) {
        if(prime[i]) {
            repb(j,i+1,MAXM) {
                if(prime[j]) {
                    ll semiprime = i*j;
                    // watch(semiprime);
                    m[semiprime]++;
                }
            }
        }
    }
}

void solve() {

    ll n; cin >> n;
    for(auto it : m) {
        if(m.find(n-it.fi) != m.end()) {
            // watch(it.fi);
            // p2(it.fi, n-it.fi);
            p1("YES");
            return;
        }
    }

    p1("NO");
}

int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    sieve();
    semiprimes();

    w(tc)
        solve();

    return 0;
}