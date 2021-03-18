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
#define sortby(v,prop) sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop < rhs.prop; });
#define rsortby(v,prop) sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop > rhs.prop; });

ll modPower(ll num,ll r) {
	if(r==0) return 1;
	if(r==1) return num%MOD;
	ll ans=modPower(num,r/2)%MOD;
	if(r%2==0) {
		return (ans*ans)%MOD;
	} return (((ans*ans)%MOD)*num)%MOD;
}

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

string rev(string s) {
	reverse(s.begin(),s.end());
	return s;
}

#define MAXM 1e14

void solve() {

	ll n;
	cin >> n;
	ll cost[n];
	string s[n], revs[n];

	rep(i,n) cin >> cost[i];
	rep(i,n) {
		cin >> s[i];
		revs[i] = rev(s[i]);
	}

	vvi dp(n,vi(2,0));	
	dp[0][0] = 0;
	dp[0][1] = cost[0];

	// dp[i][0] -> min cost when si is not reversed 
	// dp[i][1] -> min cost when si is reversed 

	repb(i,1,n) {

		ll one = MAXM, two = MAXM;
		
		if(s[i-1] <= s[i] && dp[i-1][0] < MAXM) {
			one = min(one,dp[i-1][0]);
		} 

		if(revs[i-1] <= s[i] && dp[i-1][1] < MAXM) {
			one = min(one,dp[i-1][1]);
		} 

		if(s[i-1] <= revs[i] && dp[i-1][0] < MAXM) {
			two = min(two,dp[i-1][0]+cost[i]);
		} 

		if(revs[i-1] <= revs[i] && dp[i-1][1] < MAXM) {
			two = min(two,dp[i-1][1]+cost[i]);
		} 

		if(one == MAXM && two == MAXM) {
			p1(-1);
			return;
		}

		dp[i][0] = one;
		dp[i][1] = two;
	}

	p1(min(dp[n-1][0], dp[n-1][1]));
}


int main()
{
	fastio;
	solve();
	return 0;
}