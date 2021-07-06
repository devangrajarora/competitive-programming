#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
#define vi vector<int>
#define vvi vector<vi>
#define vc vector<char>
#define vvc vector<vc>
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

    int n, m, k, minTime = INT_MAX; cin >> n >> m >> k;
    vvi time(n,vi(m));
    vvc a(n,vc(m));
    vvi psa(n+1, vi(m+1));
    int total = n*m;
    string result = "Draw";

    repeb(turn,1,total) {
    	int r,c;
    	cin >> r >> c;
    	r--, c--;
    	if(turn%2) {
    		a[r][c] = 'A';
    	} else {
    		a[r][c] = 'B';
    	}

    	time[r][c] = turn;
    }

    repeb(i,1,n) {
    	repeb(j,1,m) {
    		psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + (a[i-1][j-1] == 'A');
    	}
    }

    repeb(i,k,n) {
    	repeb(j,k,m) {
    		int x1 = i-k+1, x2 = i, y1 = j-k+1, y2 = j;
    		int ans = psa[x2][y2] - psa[x1-1][y2] - psa[x2][y1-1] + psa[x1-1][y1-1];
    		int currTime = INT_MIN;

    		// watch(ans);
    		if(ans == k*k or ans == 0) {
    			repeb(i,x1,x2) {
    				repeb(j,y1,y2) {
    					// p2(i,j);
    					currTime = max(currTime,time[i-1][j-1]);
    				}
    			}

    			if(currTime < minTime) {
	    			minTime = currTime;
	    			result = (ans == k*k) ? "Alice" : "Bob";
	    		}
    		}


    	}
    }

    p1(result);
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