#include<bits/stdc++.h>
using namespace std;
#define ll long long
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

ll m, n;
vi weights;

bool dfs(ll diff, ll prev, vi &ans) {

	if(ans.size() == m) return true;

	ll i;
	for(i = 0 ; i < n and weights[i] <= diff ; i++);
	if(i == n) return false;
	
	for(;i < n ; i++) {
		if(weights[i] != prev) {
			ans.pb(weights[i]);
			if(dfs(weights[i]-diff, weights[i],ans)) return true;
			ans.pop_back();
		}
	}

	return false;
}

void solve() {

    string s; 

    cin >> s >> m;
   	vi ans;

    rep(i,10) {
    	if(s[i] == '1') {
    		weights.pb(i+1);
    	}
    }

    n = weights.size();
    if(n == 0) {
    	p0("NO"); return;
    }

    rep(i,n) {
    	ans.pb(weights[i]);
    	if(dfs(weights[i], weights[i], ans)) {
    		p1("YES");
    		p1(ans);
    		return;
    	}
    	ans.pop_back();
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