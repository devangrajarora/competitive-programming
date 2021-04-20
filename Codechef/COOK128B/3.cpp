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

    ll evenPairs, oddPairs; cin >> evenPairs >> oddPairs;
    ll totalPairs = evenPairs + oddPairs;
    ld sq = sqrt(totalPairs);
    if(floor(sq) != ceil(sq)) {
    	p1("NO"); return;
    }

    // oddPairs = 2 * CNTodd * CNTeven
    // prod = CNTodd * CNTeven = oddPairs/2

    if(oddPairs%2) {
    	p1("NO"); return;
    }

    ll prod = oddPairs / 2; 

    // watch(prod);

    for(ll i = 1 ; i*i <= prod ; i++) {
    	if(prod % i) continue;
    	ll j =  prod / i;

    	ll CNTodd = i, CNTeven = j;
    	if(evenPairs != CNTeven*(CNTeven-1) + CNTodd*(CNTodd-1) + CNTeven + CNTodd) CNTeven = i, CNTodd = j;
    	if(evenPairs != CNTeven*(CNTeven-1) + CNTodd*(CNTodd-1) + CNTeven + CNTodd) continue;

    	p1("YES");

    	// watch(CNTodd);
    	// watch(CNTeven);

    	ll k = 2;
    	p1(CNTeven+CNTodd);
    	CNTeven--;
    	rep(i,CNTodd) {
    		p2(1,k++);
    	}

    	while(CNTeven--) {
    		p2(2,k++);
    	}

    	return;
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

    w(tc)
    	solve();
	
	return 0;
}