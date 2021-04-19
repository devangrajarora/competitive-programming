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
#define pii pair <ll,ll>
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

ll power(ll num,ll r) {
    if(r==0) return 1;
    if(r==1) return num;
    ll ans=power(num,r/2);
    if(r%2==0) {
        return (ans*ans);
    } return (((ans*ans))*num);
}

void solve() {

    ll n, gcd = 1, num, print = 0; cin >> n;
    vi a(n);

    map<ll, ll> cnt, min, secondMin;

    rep(_,n) {
    	cin >> num;

    	for(ll i = 2 ; i*i <= num ; i++) {
	    	if(num%i==0) {
	    		cnt[i]++;
	    		ll k = 0;
	    		while(num%i==0) {
	    			num /= i; k++;
	    		}

	    		if(min[i] == 0) min[i] = k;
	    		else {
	    			if(min[i] >= k) {
	    				secondMin[i] = min[i]; min[i] = k;
	    			} else if(secondMin[i] == 0 or secondMin[i] > k) {
	    				secondMin[i] = k;
	    			}
	    		}
	    	}
	    }

    	if(num != 1) {
    		cnt[num]++;
    		if(min[num] == 0) min[num] = 1;
    		else {
    			if(min[num] >= 1) {
    				secondMin[num] = min[num]; min[num] = 1;
    			} else if(secondMin[num] == 0 or secondMin[num] > 1) {
    				secondMin[num] = 1;
    			}
    		}
    	}
    } 

    ll ans = 1;
    for(auto &it : cnt) {
    	if(it.se == n) {
    		// p1(it);
    		ans *= power(it.fi,secondMin[it.fi]);
    	} else if(it.se == n-1) {
    		ans *= power(it.fi,min[it.fi]);
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
    //w(tc)
        solve();
	return 0;
}