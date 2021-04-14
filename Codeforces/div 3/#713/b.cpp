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

	ll n; cin >> n;
	vector<string> a(n);
	rep(i,n) {
		cin >> a[i];
	}    

	ll one = 0, a1, a2, b1, b2;

	rep(i,n) {
		rep(j,n) {
			if(a[i][j] == '*') {
				if(one) {
					a2 = i, b2 = j;
				} else {
					one = 1;
					a1 = i, b1 = j;
				}
			}
		}
	}

	ll r1, r2, c1, c2;

	if(a1 == a2) {
		c1 = b1, c2 = b2;
		if(a1 == 0) {
			r1 = a1+1, r2 = a2+1;
		} else {
			r1 = a1-1, r2 = a2-1;
		}

	} else if(b1 == b2) {
		r1 = a1, r2 = a2;
		if(b1 == 0) {
			c1 = b1+1, c2 = b2+1;
		} else {
			c1 = b1-1, c2 = b2-1;
		}

	} else {
		r1 = a1, c1 = b2, r2 = a2, c2 = b1;
	}

	// p2(r1,c1);
	// p2(r2,c2);

	rep(i,n) {
		rep(j,n) {
			if(i == r1 and j == c1) {
				a[i][j] = '*';
			} else if(i == r2 and j == c2) {
				a[i][j] = '*';
			}
		}
	}

	rep(i,n) p1(a[i]);
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