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

/*-------------------------------------------------*/

ll best(ll d) {

	ll l = 1, h = 32;

	while(l <= h) {
		ll mid = (l+h)/2;
		ll x = powl(2,mid);
		
		if((x-1 >= d) && ((x/2)-1) < d) {
			return mid;
		} else if(x-1 < d) {
			l = mid + 1;
		} else {
			h = mid-1;
		}
	}

	return -1;
}

void solve() {

	ll n, diff = 0;
	cin >> n;
	ll a[n];
	
	rep(i,n) cin >> a[i];
	ll mx = a[0];
	
	// get biggest diff to be covered
	repb(i,1,n) {
		
		if(a[i] < mx) {
			diff = max(diff, mx-a[i]);
		}
		mx = max(mx,a[i]);
	}

	ll ans = 0;
	// number of steps to cover the distance
	if(diff > 0) ans = best(diff);
	p1(ans);
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

/*
1
5
5 -10 2 -9 -5
*/