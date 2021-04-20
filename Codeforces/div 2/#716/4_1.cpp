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

    
/*-------------------------------------------------*/

// read once, read again, think, code

void solve() {

	ll n,q,num; cin >> n >> q;

	vector<map<int,int>> m(n+1);
	
	repeb(i,1,n) {
		cin >> num;
		m[i] = m[i-1];
		m[i][num]++;
	}

	rep(i,q) {
		ll l, r;
		cin >> l >> r;
		ll x = r-l+1, ok = 0;

		map<int,int> curr;
		for(auto &it : m[r]) {
			curr[it.fi] = m[r][it.fi] - m[l-1][it.fi];
			if(curr[it.fi] > ceil(x/2.0)) {
				ll y = curr[it.fi];
				ll rem = x-y;
                ll onepiece = 2*rem+1;
				ll ans = x-onepiece+1;
				p1(ans); ok = 1; break;
			}
		}

        if(ok) continue;
		p1(1);
	}

}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    // w(tc)
    	solve();
	
	return 0;
}