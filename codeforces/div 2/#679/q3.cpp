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
#define w(x)  ll x; cin>>x; while(x--)

ll modPower(ll num,ll r) {
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
#define watch(x) p3(#x,":",x)

void solve() {

    vi a(6);

    rep(i,6) {
        cin >> a[i];
    }

    vector<pii> v;

    ll n, num;
    cin >> n;

    rep(i,n) {
        cin >> num;
        rep(j,6) {
            // fi -> fret no, se -> melodyno
            v.pb({num-a[j], i});
        }
    }
    
    sortby(v,fi);

    ll l = 0, r = 1, ans = 1e14;
    ll covered = 1;
    vi cnt(n,0);
    cnt[v[0].se]++;

    // p1(v);

    while(l < v.size()) {

        r = max(l,r);
        while(r < v.size()) {

            if(cnt[v[r].se] == 0) covered++;
            cnt[v[r].se]++;
            
            if(covered == n) {
                while(cnt[v[l].se] > 1) cnt[v[l].se]--,l++;
                ans = min(ans, v[r].fi-v[l].fi);
                r++;
                break;
            }
            r++;
        }

        if(covered != n && r==v.size()) {
            break;
        }

        cnt[v[l].se]--;
        if(cnt[v[l].se] == 0) covered--;
        l++;
    }

    p1(ans);
}


int main()
{
    fastio;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdin);
    #endif
    solve();
    return 0;
}