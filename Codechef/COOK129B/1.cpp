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

#define MAXM 1001
int a[MAXM][MAXM];

void solve() {

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dp[MAXM][MAXM];
    memset(dp,0,sizeof(dp));

    for(int i = x1 ; i <= x2 ; i++) {
    	for(int j = y1 ; j <= y2 ; j++) {
    		dp[i][j] = a[i][j] + max(dp[i-1][j], dp[i][j-1]);
    	}
    }

    p1(dp[x2][y2]);
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif


    a[1][1] = 1;
    int cnt = 1;

    for(int i = 1 ; i < MAXM ; i++) {
    	int curr = cnt;
    	cnt++;
    	for(int j = 2 ; j < MAXM ; j++) {
    		a[i][j] = a[i][j-1] + curr;
    		curr++;
    	}

    	if(i < MAXM-1) {
    		a[i+1][1] = 1 + a[i][2];
    	}
    }

    w(tc)
    	solve();
	
	return 0;
}