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

ll findMex(vi &a, ll st, ll en) {
	ll n = a.size();
	vi buckets(n+1,0);
	for(int i = st ; i < en ; i++) {
		ll num = a[i];
		if(num >= 0 and num < n) {
			buckets[num] = 1;
		}
	}

	int i;
	for(i = 0 ; i <= n ; i++) {
		if(buckets[i] == 0) return i;
	} return i;
}

void solve() {

	ll n, m;  cin >> n >> m;
	vi a(n), cnt(n,0);
	rep(i,n) {
		cin >> a[i];
		if(i < m) cnt[a[i]]++;
	}


    ll mex = findMex(a,0,m); // O(m)
    ll ans = mex;
    // p1(mex);

    for(int i = 1 ; i + m <= n ; i++) {
    	if(ans == 0) break;
    	cnt[a[i-1]]--;
    	cnt[a[i+m-1]]++;
    	// p2(a[i+m-1],mex);

    	if(a[i-1] < mex and cnt[a[i-1]] == 0) {
    		mex = a[i-1];
    	} else if(a[i+m-1] == mex) {
    		mex = findMex(a,i,i+m);
    	}

    	ans = min(ans,mex);
    } 

    p1(ans);
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    //w(tc)
    	solve();
	
	return 0;
}