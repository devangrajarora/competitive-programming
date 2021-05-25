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

#define FLUSH fflush(stdout)

// consider range l...r to find kth zero

// const int N = 6;
// int a[N] = {1,0,1,1,0,1};
// vi psa(N+1);

// ll checker(ll l, ll r) {
// 	return psa[r] - psa[l-1];
// }


void func(ll l, ll r, ll k) {
	if(l == r and k == 1) {
		cout << "! " << l << "\n";
		FLUSH;
		return;
	}

	ll mid = (l + r) / 2, zeroes, ones;
	cout << "? " << l << " " << mid << "\n";
	// ones = checker(l,mid);
	FLUSH;
	cin >> ones;
	zeroes = mid-l+1 - ones;
	// watch(zeroes);

	if(zeroes >= k) {
		func(l,mid,k);
	} else {
		func(mid+1,r,k-zeroes);
	}
}

void solve() {

	FLUSH;
    ll n, t; cin >> n >> t;
    while(t--) {
    	FLUSH;
    	ll k; cin >> k;
    	func(1,n,k);
    }

}


int main()
{
	// fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    // repeb(i,1,N) {
    // 	psa[i] = psa[i-1] + a[i-1];
    // }

    solve();
	
	return 0;
}