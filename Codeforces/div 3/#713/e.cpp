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

ll high(ll n, ll k) {
	return (k * (2*n - k + 1))/2;
}

ll low(ll k) {
	return (k * (k + 1))/2;
}

void solve() {

    ll n,l,r,s;
    cin >> n >> l >> r >> s;
    vi ans(n,-1);
    l--, r--;

    unordered_map<ll, ll> used;
    used.reserve(1<<10);
    used.max_load_factor(0.25);

    ll curr = n, idx = l, k = r-l+1;

    rfor(i,n-1,0) {
    	ll len = i+1;
    	if(k > 0 and s <= high(len,k) and s - curr >= low(k-1)) {
    		ans[idx++] = curr;
    		used[curr] = 1;
    		s -= curr;
    		k--;
    	}

    	curr--;
    }

    if(s != 0 or k != 0) {
    	p1(-1);
    } else {

    	ll pos = 0, num = 1, done = r-l+1;

    	while(done != n) {
    		if(ans[pos] != -1) pos++;
    		else if(used[num]) num++;
    		else {
    			ans[pos] = num;
    			pos++; num++;
    			done++;
    		}
    	}

    	p1(ans);
    }
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