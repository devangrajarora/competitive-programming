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

	ll n, sum = 0, mx = 0; cin >> n;
	bool allsame = true;
	vi a(n);
	rep(i,n) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
		if(i > 0 and a[i] != a[i-1]) allsame = false; 
	}

	if(allsame) {
		p1(0); return;
	}

	int ok = 0;

	for(ll parts = n-1 ; parts > 1 ; parts--) {
		if(sum%parts != 0) continue;
		ll subarraySum = sum / parts;
		if(mx > subarraySum) continue;

		ll k = parts, currsum = 0;
		rep(i,n) {
			if(currsum == subarraySum) {
				k--;
				currsum = a[i];
			} else {
				if(currsum + a[i] > subarraySum) break;
				currsum += a[i];
			}
		}

		if(currsum == subarraySum) {
				k--;
		}


		if(k == 0) {
			p1(n-parts);
			ok = 1;
			return;
		}
	}

		p1(n-1);
	
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