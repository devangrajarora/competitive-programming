#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i <= b ; i++)
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

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

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

// read once, read again, think, code

void solve() {

	ll num;
	vi n(3), sum(3), MIN(3,INT_MAX);
	rep(i,3) cin >> n[i];

	rep(i,3) {
		rep(j,n[i]) {
			cin >> num;
			sum[i] += num;
			MIN[i] = min(MIN[i], num);
		}
	} 

	// p1(n);
	// p1(MIN);
	// p1(sum);
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