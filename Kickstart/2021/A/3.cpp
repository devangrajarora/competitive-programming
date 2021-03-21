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
#define popb pop_back()
#define endl "\n"
#define vi vector<ll>
#define vb vector<bool>
#define vvb vector<vb>
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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define w(x)  ll x; cin>>x; while(x--)

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

void cases(int tc) {
    cout << "Case #" << tc << ": ";
}

ll n, m;

bool valid(int r, int c) {
    return 0 <= r and r < n and 0 <= c and c < m;
}

void solve(int tc) {

    cin >> n >> m;
    vvi a(n,vi(m));
    ll ans = 0;

    rep(i,n) rep(j,m) cin >> a[i][j];

    while(true) {
        bool ok = true;

        rep(r,n) {
            rep(c,m) {
                rep(i,4) {
                    ll nr = r + dr4[i], nc = c + dc4[i];
                    if(valid(nr,nc) and a[r][c] > a[nr][nc] + 1) {
                        ok = false;
                        ans += a[r][c] - (a[nr][nc]+1);
                        a[nr][nc] = a[r][c]-1;
                    }
                }
            }
        }

        if(ok) break;
    }

    cases(tc);
    p1(ans);
}

int main()
{
    fastio;

    // #ifndef ONLINE_JUDGE
    //     freopen("/home/devang/input.txt","r",stdin);
    //     freopen("/home/devang/output.txt","w",stdout);
    // #endif

    int tc,x = 1;
    cin >> tc;

    while(tc--) {
        solve(x++);
    }

    return 0;
}