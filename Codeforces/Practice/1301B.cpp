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

void solve() {

	ll n, smallNext = INT_MAX, bigNext = INT_MIN;
	cin >> n;

	ll a[n], mx = 0;
	rep(i,n) {
		cin >> a[i];
	}

	rep(i,n) {

		if(a[i] != -1){
			if(i < n-1 && a[i+1] != -1) {
				mx = max(mx, abs(a[i] - a[i+1]));
			}
			if(i > 0 && a[i-1] != -1) {
				mx = max(mx, abs(a[i] - a[i-1]));		
			}
		} else {
			if(i < n-1 && a[i+1] != -1) {
				bigNext = max(bigNext, a[i+1]);	
				smallNext = min(smallNext, a[i+1]);
			}
			if(i > 0 && a[i-1] != -1) {
				bigNext = max(bigNext, a[i-1]);	
				smallNext = min(smallNext, a[i-1]);
			}	
		} 		
	}

	if(bigNext == INT_MIN) {
		p2(0,0);
		return;
	}

	ll l = 0, h = 1e9, minDiff = INT_MAX, bestK;

	while(l <= h) {

		ll k = (l+h)/2;
		ll currMaxDiff = max({abs(bigNext-k), abs(smallNext-k),mx});

		if(currMaxDiff < minDiff) {
			minDiff = currMaxDiff;
			bestK = k;
		} 

		// p4("k:",k,"currDiff:",currMaxDiff);

		ll big = bigNext-k, small = smallNext-k;

		if(big < 0 && small < 0) {
			h = k - 1;
		} else if(big > 0 && small > 0) {
			l = k + 1;
		} else {
			// k lies between smallNext and bigNext
			if(k-smallNext > bigNext-k) {
				h = k - 1;
			} else {
				l = k + 1;
			}
		}
	}

	p2(minDiff, bestK);
}


int main()
{
	fastio;
	int tc;
	cin >> tc;

	while(tc--)	{
		solve();
	}

	return 0;
}