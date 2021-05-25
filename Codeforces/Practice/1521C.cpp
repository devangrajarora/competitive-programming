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

#define FLUSH fflush(stdin); fflush(stdout)

int query(int t, int i, int j, int x) {
	cout << "? " << t << " " << i << " " << j << " " << x << "\n";  FLUSH;
	int res; cin >> res; return res;

	// if(t == 1) {
	// 	return max(min(x,p[i]),min(x+1,p[j]));
	// } else {
	// 	return min(max(x,p[i]),max(x+1,p[j]));
	// }
}

void solve() {

    int n, res; cin >> n;
    vector<int> ans(n+1);

    int knownIdx = -1, knownVal = -1;

    int i = 1;
    while(i < n) {
    	int res = query(2,i,i+1,1);
    	if(res == 1) {
    		knownIdx = i, knownVal = 1; break;
    	} else if(res == 2) {
    		res = query(2,i+1,i,1);
    		if(res == 1) {
    			knownIdx = i+1;
    			knownVal = 1;
    			break;
    		}
    	}

    	i += 2;
    }

    if(knownIdx == -1) {
    	knownIdx = n;
    	knownVal = 1;
    }

    ans[knownIdx] = knownVal;

    repeb(i,1,n) {
    	if(i == knownIdx) continue;
    	int res = query(1,knownIdx,i,n-1);
    	ans[i] = res;
    }

    cout << "! ";
    repeb(i,1,n) p0(ans[i]);
    p1("");
    FLUSH;
}


int main()
{
	// fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    w(tc)
    	solve();
	
	return 0;
}