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

ll eegcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = eegcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool get_any_solution(ll a, ll b, ll c, ll &g, ll &X0, ll &Y0) {

    g = eegcd(abs(a),abs(b),X0,Y0);
    if(c%g) {
        return false;
    }

    X0 *= c/g;
    Y0 *= c/g;

    if(a < 0) X0 = -X0;
    if(b < 0) Y0 = -Y0;
    bool xBT = X0 < 0, yBT = Y0 < 0;

    if(xBT and yBT) return false;

    while(yBT) {
        ll X1 = X0 - b/g;
        ll Y1 = Y0 + a/g;
        if(X1 >= 0 and Y1 >= 0) {
            X0 = X1, Y0 = Y1;
            return true;
        }
        if(X1 < 0) {
            X0 = X1, Y0 = Y1;
            return false;
        }

        X0 = X1, Y0 = Y1;
    }

    while(xBT) {
        ll X1 = X0 + b/g;
        ll Y1 = Y0 - a/g;
        if(X1 >= 0 and Y1 >= 0) {
            X0 = X1, Y0 = Y1;
            return true;
        }
        if(Y1 < 0) {
            X0 = X1, Y0 = Y1;
            return false;
        }

        X0 = X1, Y0 = Y1;
    }

    return true;
}

void solve() {

    ll a, b, c; cin >> a >> b >> c;
    ll g, X0, Y0;
    bool ans = get_any_solution(a,b,c,g,X0,Y0);
    // p2(X0, Y0);
    (ans) ? p1("Yes") : p1("No");
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

    //w(tc)
    	solve();
	
	return 0;
}