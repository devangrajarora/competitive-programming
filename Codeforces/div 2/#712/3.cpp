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

void solve() {

    ll n, one = 0, zero = 0; cin >> n;
    string s;
    cin >> s;

    rep(i,n) {
    	(s[i] == '0') ? zero++ : one++;
    }

    if(s[0] == '0' or s[n-1] == '0' or (zero > 0 and (zero%2 or one%2))) {
    	p1("NO");
    	return;
    }

    string a(n,'0');
    string b(n,'0');
    a[0] = b[0] = '(';
    a[n-1] = b[n-1] = ')';
    bool flip = true;
    rep(i,n) {
    	if(s[i] == '0') {
    		if(flip) {
    			a[i] = '('; b[i] = ')';
    		} else {
    			a[i] = ')'; b[i] = '(';
    		}
    		flip = !flip;
    	}
    }

    flip = true;
   	repb(i,1,n-1) {
    	if(s[i] == '1') {
    		if(flip) {
    			a[i] = '('; b[i] = '(';
    		} else {
    			a[i] = ')'; b[i] = ')';
    		}
    		flip = !flip;
    	}
    }

    p1("YES");
    p1(a);
    p1(b);
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