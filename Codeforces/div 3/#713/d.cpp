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

    ll n, totalSum = 0; cin >> n;
    vi a(n+2);
    
    unordered_map<int, int> m;
    m.reserve(1<<10);
    m.max_load_factor(0.25);

    rep(i,n+2) {
        cin >> a[i];
        totalSum += a[i];
        m[a[i]]++;
    }


    ll X = -1, sumVal = -1;

    for(auto &x : a) {
        ll lookFor = totalSum - x;
        if(lookFor % 2) continue;
        if(m[lookFor/2] > 0) {

            X = x; sumVal = lookFor/2;

            vi b;
            ll k = 0, done = 0, xcounted = 0, sumValCounted = 0;

            rep(i,n+2) {
                if(a[i] == X and xcounted == 0) {
                    xcounted = 1;
                    continue;
                }

                if(a[i] == sumVal and sumValCounted == 0) {
                    sumValCounted = 1;
                    continue;
                }


                b.pb(a[i]);
                done++;
            }

            if(done != n) {
                continue;
            } else {
                ll target = 0;
                for(auto &num : b) {
                    target += num;
                }

                if(target == sumVal) {
                    p1(b);
                    return;

                } else continue;
            }
        }
    }

    p1(-1);
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