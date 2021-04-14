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

const ll MAXM = 2e5+1;
ll cnt[10][MAXM][10];

// cnt[s][op][d] -> no of digits d which are formed from digit s after op operations

void solve() {

    string s; ll m, ans = 0;
    cin >> s >> m;

    for(char c : s) {
        int digit = c-'0';
        for(int end = 0 ; end < 10 ; end++) {
            ans = (ans + cnt[digit][m][end]) % MOD;
        }
    }

    p1(ans);
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

    memset(cnt,0,sizeof(cnt));

    for(int src = 0 ; src < 10 ; src++) {
        cnt[src][0][src] = 1;
        for(ll op = 1 ; op < MAXM ; op++) {
            for(int dest = 0 ; dest < 10 ; dest++) {

                if(dest == 0) {
                    cnt[src][op][dest] = cnt[src][op-1][9];
                } else if(dest == 1) {
                    cnt[src][op][dest] = (cnt[src][op-1][0] + cnt[src][op-1][9]) % MOD;
                } else {
                    cnt[src][op][dest] = cnt[src][op-1][dest-1];
                }
            }
        }
    }

    w(tc)
    	solve();
	
	return 0;
}