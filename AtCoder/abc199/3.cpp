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
    bool flipped = false;
    ll q; cin >> q;
    
    while(q--) {
    	ll ti, ai, bi;
    	cin >> ti >> ai >> bi;
    	if(ti == 1) {

    		ai--, bi--;
    		if(ai > bi) swap(ai,bi);
    		if(!flipped) {
    			swap(s[ai], s[bi]);
    		} else {
    			if(ai >= n) {
    				ai -= n;
    				bi -= n;
    			} else if(ai < n and bi >= n) {
    				ai += n;
    				bi -= n;
    			} else {
    				ai += n;
    				bi += n;
    			}

    			swap(s[ai], s[bi]);
    		}

    	} else {
    		flipped ^= 1;
    	}
    }

    if(!flipped) p1(s);
    else {
    	repb(i,n,2*n) cout << s[i];
    	rep(i,n) cout << s[i];
    }
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