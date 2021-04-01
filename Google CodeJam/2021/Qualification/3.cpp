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
    for(unsigned int i = 0; i < v.size(); i++)
    {
        if(!first)
            os << " ";
        os << v[i];
        first = false;
    }
    return os;
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

ll n;

void rev(vi &ans, int idx, ll cost) {

    ll len = n-idx;
    if(len <= 1) return;
    
    ll currCost = 1, nextLen, nextCost;
    for(ll currCost = 1 ; currCost <= len ; currCost++) {
        nextLen = len-1, nextCost = cost - currCost;

        if(nextCost >= nextLen-1 and nextCost <= (nextLen)*(nextLen+1)/2 - 1) {
            ll remainingCost = cost - nextCost;
            rev(ans, idx+1, nextCost);
            reverse(ans.begin() + idx, ans.begin()+idx+remainingCost);
            return;
        }
        
    }
}

void solve(int tc) {

	ll c; cin >> n >> c;

	if(c < n-1 or c > (n*(n+1))/2 - 1) {
		cases(tc); p1("IMPOSSIBLE");
		return;
	}

	vi ans(n);
    rep(i,n) ans[i] = i+1;

    rev(ans,0,c); 

    cases(tc);
    p1(ans);
}

int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    int tc,x = 1;
    cin >> tc;

    while(tc--)	{
      solve(x++);
  }

  return 0;
}