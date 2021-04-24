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

    ll n, sum = 0, odd = 0, oddIdx, allZero = 1;
	cin >> n;

	vi a(n);

	rep(i,n) {
		cin >> a[i];
		sum += a[i];
		if(a[i] != 0) allZero = 0;
		if(a[i]%2 and odd == 0) {
			odd = 1; oddIdx = i+1;
		}
	}

	if(allZero) {
		p1(n);
		repeb(i,1,n) p0(i);
		return;
	}

	if(sum % 2 == 1) {
		p1("0"); return;
	}

	ll m = sum/2;
	bool dp[n+1][m+1];
	repe(i,n) dp[i][0] = true;
	repe(j,m) dp[0][j] = false;
	
	
	repeb(i,1,n) {
		repeb(j,1,m) {
			if(a[i-1] > j) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j] || dp[i-1][j - a[i-1]];
			}
		}
	}


	if(!dp[n][m]) {
		p1("0"); return;
	}

	if(dp[n][m] and odd > 0) {
		p1(1); p1(oddIdx); return;
	}

	// all even

	rep(i,n) {
		ll newSum = (sum-a[i])/2; // always even
		if(!dp[n][newSum]) {
			p1(1); p1(i+1); return;
		}
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