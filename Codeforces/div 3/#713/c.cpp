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

bool check(string &s) {
    ll n = s.size();

	ll l = 0, r = n-1;
    while(l <= r) {
    	if(s[l] != s[r]) return false;
    	l++; r--;
    }

    return true;
}

void solve() {

    ll a, b, q = 0; cin >> a >> b;
    string s;
    cin >> s;
    ll n = s.size();

    if(a%2==1 and b%2==1) {
    	p1(-1); return;
    }

    rep(i,n) {
    	if(s[i] == '1') b--;
    	else if(s[i] == '0') a--;
    	else q++;
    }

    if(q==0) {
    	if(check(s) and a == 0 and b == 0) {
    		p1(s);
    	} else {
    		p1(-1);
    	}

    	return;
    }

    ll l = 0, r = n-1;

    while(l < r) {
    	if(s[l] != '?' and s[r] != '?') {
    		if(s[l]!=s[r]) {
    			p1(-1); return;
    		}
    	} else if(s[l] == '?' and s[r] != '?') {
    		s[l] = s[r];
    		if(s[r] == '1') {
    			if(b == 0) {
    				p1(-1); return;
    			} else b--;
    		} else {
    			if(a == 0) {
    				p1(-1); return;
    			} else a--;
    		}
    	} else if(s[l] != '?' and s[r] == '?') {
    		s[r] = s[l];
    		if(s[l] == '1') {
    			if(b == 0) {
    				p1(-1); return;
    			} else b--;
    		} else {
    			if(a == 0) {
    				p1(-1); return;
    			} else a--;
    		}
    	} 

    	l++; r--;
    }

     l = 0, r = n-1;

    while(l < r) {
    	if(s[l] == '?' and s[r] == '?') {
    		if(a >= 2) {
    			s[l] = s[r] = '0';
    			a -= 2;
    		} else if(b >= 2) {
    			s[l] = s[r] = '1';
    			b -= 2;
    		} else {
    			p1(-1); return;
    		}
    	} l++; r--;
    }

    if(l == r) {
    	if(s[l] == '?') {
    		if(a >= 1) {
    			s[l] = '0'; a--;
    		} else if(b >= 1) {
    			s[l] = '1'; b--;
    		}
    	}
    }

    if(a == 0 and b == 0) p1(s);
    else p1(-1);	
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