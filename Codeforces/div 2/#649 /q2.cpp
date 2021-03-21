#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define repe(i,n) for(int i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(int i = a ; i < b ; i++)
#define repeb(i,a,b) for(int i = a ; i <= b ; i++)
#define rfor(i,n,a) for(int i = n ; i >= a ; i--)
#define pb push_back
#define popb pop_back()
#define endl "\n"
#define pii pair<int,int> 
#define pll pair < long long, long long >
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

ll power(ll num,ll r){
    if(r==0) return 1;
    if(r==1) return num%MOD;
    ll ans=power(num,r/2)%MOD;
    if(r%2==0) {
        return (ans*ans)%MOD;
    } return (((ans*ans)%MOD)*num)%MOD;
}

/*-------------------------------------------------*/

void solve() {

	int n;
	cin >> n;

	ll a[n];

	rep(i,n) {
		cin >> a[i];
	}

	vector<ll> ans;
	ans.pb(a[0]);

	bool increasing = (a[1] > a[0]); 

	int mx = INT_MIN, mn = INT_MAX;

	if(increasing) {
		mx = a[1];
	} else {
		mn = a[1];
	}

	repb(i,1,n-1) {

		if(increasing) {
			if(a[i] >= mx) {
				mx = a[i];
				// p2("mx:",mx);
			} else {
				ans.pb(mx);
				mx = INT_MIN;
				increasing = false;
				mn = a[i];
			}
		} else {
			if(a[i] <= mn) {
				mn = a[i];
			} else {
				ans.pb(mn);
				mn = INT_MAX;
				increasing = true;
				mx = a[i];
			}
		}
	}

	if(increasing && mx > a[n-1]) {
		ans.pb(mx);
	}

	if(!increasing && mn < a[n-1]) {
		ans.pb(mn);
	}

	ans.pb(a[n-1]);
	p1(ans.size());
	for(auto num : ans) {
		cout << num << " ";
	}

	cout << "\n";
	
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