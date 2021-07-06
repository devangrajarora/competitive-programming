#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD = 1000000007;
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

class Pair {
public:
	ll sum;
	ll len;

	Pair() {
		sum = 0;
		len = 0;
	}

	Pair(ll sum, ll len) {
		this->sum = sum;
		this->len = len;
	}
};

void print(Pair &a) {
	p2(a.sum,a.len);
}

Pair compare(Pair &a, Pair &b) {
	// 1. length
	// 2. sum
	if(a.len == b.len) {
		return (a.sum > b.sum) ? a : b;
	} else {
		return (a.len > b.len) ? a : b;
	}
}

const ll ninf = -1e12;

void solve() {

    ll n, potion;
    cin >> n;

	Pair prevInc = Pair(ninf,ninf), prevExc = Pair(0,0), currInc, currExc;    

    repeb(i,1,n) {
    	cin >> potion;
    	Pair sum00 = (prevExc.sum >= 0) ? Pair(prevExc.sum, prevExc.len) : Pair(ninf,ninf);
    	Pair sum10 = (prevInc.sum >= 0) ? Pair(prevInc.sum, prevInc.len) : Pair(ninf,ninf);
    	Pair sum01 = (prevExc.sum + potion >= 0 and prevExc.sum >= 0) ? Pair(prevExc.sum + potion, prevExc.len + 1) : Pair(ninf,ninf);
    	Pair sum11 = (prevInc.sum + potion >= 0 and prevInc.sum >= 0) ? Pair(prevInc.sum + potion, prevInc.len + 1) : Pair(ninf,ninf);

    	currExc = compare(sum00,sum10);
    	currInc = compare(sum01,sum11);

    	prevExc = currExc;
    	prevInc = currInc;

    	cout << "POTION " << potion << ":\n";
    	print(currExc);
    	print(currInc);
    }

    ll ans = max(prevExc.len, prevInc.len);
    p1(ans);
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