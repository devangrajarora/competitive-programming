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

#define vb vector<bool>
#define vvb vector<vb>

int ord(char c) {
	return c-'0';
}

void solve() {

	string s;
	cin >> s;
	int n = s.size();
	vvb dp(n, vb(8, false));
	vvi prev(n, vi(8, -1));

	// dp[i][j] -> there exists some sequence in first i chars for which sequence % 8 is j

	dp[0][ord(s[0])%8] = true;

	repb(i,1,n) {
		dp[i][ord(s[i]) % 8] = true;
		rep(j,8) {
			if(dp[i-1][j]) {
				dp[i][j] = true; // ignore ith character
				dp[i][(j*10 + ord(s[i])) % 8] = true; // include ith character
				prev[i][j] = j;
				prev[i][(j*10 + ord(s[i])) % 8] = j;
			}
		}
	}

	ll num = 0;

	rep(i,n) {
		if(dp[i][0]) {
			ll currI = i, currJ = 0;
			string ans = "";
			while(true) {

				if(prev[currI][currJ] == -1 or prev[currI][currJ] != currJ) { // whenever we change modulo, we include that number
					ans += (s[currI]);
				}

				if(prev[currI][currJ] == -1) break;

				currJ = prev[currI][currJ];
				currI--;
			}

			reverse(ans.begin(), ans.end());
			p1("YES"); p1(ans); return;

		}
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

    //w(tc)
    	solve();
	
	return 0;
}