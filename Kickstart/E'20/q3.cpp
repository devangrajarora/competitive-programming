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
#define pii pair<int,int> 
#define pll pair < long long, long long >
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

/*-------------------------------------------------*/

void cases(int tc) {
	cout << "Case #" << tc << ": ";
}

void print(vector<ll> &a) {
	for(auto num : a) p0(num);
	cout << "\n";
}

void solve(int tc) {

	ll n, sum = 0;
	cin >> n;

	vector<ll> e(n),r(n), prefix(n+1);
	prefix[0] = 0;

	rep(i,n) {
		cin >> e[i] >> r[i];
		sum += e[i];
		prefix[i+1] = e[i] + prefix[i];
	}

	ll ans = sum, remove = 0;

	set<ll> blocks;

	rep(i,n) {
		if(sum - e[i] < r[i]) {
			blocks.insert(i);
		}
	}

	if(n == 1) {
		cases(tc);
		p2(0,e[0]);
		return;
	}

	if(blocks.size() == 0) {
		cases(tc);
		p2(0,"INDEFINITELY");
		return;
	}

	

}


int main()
{
	fastio;
	int tc,x = 1;
	cin >> tc;

	while(tc--)	{
		solve(x++);
	}

	return 0;
}