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
#define popb pop_back()
#define endl "\n"
#define vi vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair < long long, long long >
typedef priority_queue<ll, vector<ll>, greater<ll>> minheap;
typedef priority_queue<ll> maxheap;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
#define sortv(v) sort(v.begin(),v.end())
#define rsortv(v) sort(v.begin(),v.end(), greater<>());
#define watch(x) cout << (#x) << " is " << (x) << endl
#define w(x)  ll x; cin>>x; while(x--)

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
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
        {
            if(!first)
                os << ", ";
            os << *iii;
            first = false;
        }
        return os << "]";
    }
 
    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
        {
            if(!first)
                os << ", ";
            os << *iii ;
            first = false;
        }
        return os << "]";
    }

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code

#define INF 1e9

// linear space

void solve1() {

	ll cj, jc, n; string s;
	cin >> cj >> jc >> s;
	n = s.size();

	// dp[i][0] -> minimum cost after ith character when we put C at ith position
	// dp[i][1] -> minimum cost after ith character when we put J at ith position

	vvi dp(2,vi(n,INF));
	dp[0][0] = (s[0] == '?' or s[0] == 'C') ? 0 : INF;
	dp[1][0] = (s[0] == '?' or s[0] == 'J') ? 0 : INF;

	for(int i = 1 ; i < n ; i++) {

		ll put_C = INF, put_J = INF;

		if(s[i] == '?' or s[i] == 'C') {
			put_C = min(dp[0][i-1], dp[1][i-1] + jc);
		}	

		if(s[i] == '?' or s[i] == 'J') {
			put_J = min(dp[1][i-1], dp[0][i-1] + cj);
		} 

		dp[0][i] = put_C;
		dp[1][i] = put_J;
	}

	p1(min(dp[0][n-1], dp[1][n-1]));
}

// constant space

void solve() {

	ll CJ, JC, n; cin >> CJ >> JC;
	string s; cin >> s;
	n = s.size();

	ll C_prev = (s[0] == 'C' or s[0] == '?') ? 0 : INF;
	ll J_prev = (s[0] == 'J' or s[0] == '?') ? 0 : INF;

	for(int i = 1 ; i < n ; i++) {

		ll C_here = INF, J_here = INF;

		if(s[i] == 'C' or s[i] == '?') C_here = min(C_prev, J_prev + JC); 
		if(s[i] == 'J' or s[i] == '?') J_here = min(J_prev, C_prev + CJ); 
		
		C_prev = C_here;
		J_prev = J_here;
	}

	p1(min(C_prev, J_prev));
}

int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

	int tc;
	cin >> tc;

	for(int x = 1 ; x <= tc ; x++)	{
		cout << "Case #" << x << ": ";
		solve();
	}

	return 0;
}