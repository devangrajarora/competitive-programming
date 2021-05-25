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

void solve() {

    ll n; cin >> n;
    string s; cin >> s;
    vi lastDotToLeft(n), lastDotToRight(n);
    vi costLeft(n), costRight(n);

    unordered_map<ll, ll> m;
    m.reserve(1<<10);
    m.max_load_factor(0.25);
    
    lastDotToLeft[0] = -1;
    costLeft[0] = 0;
    ll lastDot = -1, cnt = (s[0] == '*');
    repb(i,1,n) {
    	if(s[i] == '.') {
    		lastDot = i;
    		costLeft[i] = costLeft[i-1] + cnt;
    	} else {
    		lastDotToLeft[i] = lastDot;
    		costLeft[i] = (lastDot == -1) ? 0 : costLeft[lastDot];
    		cnt++;
    	}
    }	


	lastDotToRight[n-1] = -1; 
	costRight[n-1] = 0;
    lastDot = -1, cnt = (s[n-1] == '*');
    rfor(i,n-2,0) {
    	if(s[i] == '.') {
    		lastDot = i;
    		costRight[i] = costRight[i+1] + cnt;
    	} else {
    		lastDotToRight[i] = lastDot;
    		costRight[i] = (lastDot == -1) ? 0 : costRight[lastDot];
    		cnt++;
    	}
    }

    ll ans = LLONG_MAX;

    rep(i,n) {
    	if(s[i] == '*') {
    		ll curr = (lastDotToLeft[i] == -1) ? 0 : costLeft[lastDotToLeft[i]];
    		curr += (lastDotToRight[i] == -1) ? 0 : costRight[lastDotToRight[i]];
    		ans = min(ans, curr);
    	} else {
    		ll op1 = costLeft[i] + ((i == n-1) ? 0 : costRight[i+1]);
    		ll op2 = ((i == 0) ? 0 : costLeft[i-1]) + costRight[i];
    		ans = min({ans, op1, op2});
    	}
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