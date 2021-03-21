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

	int n, x, sum = 0, l, r, num;
	cin >> n >> x;

	bool possible = false, flag = true;

	rep(i,n) {
		cin >> num;
		sum += num;
		if(num % x != 0) {
			possible = true;
		}

		if(flag && num % x != 0) {
			l = i + 1;
			flag = false;
		}

		if(num % x != 0) {
			r = i - 1;
		}
	}

	if(!possible) {
		p1(-1);
	} else if(sum % x != 0) {
		p1(n);
	} else {
		int len1 = n - l, len2 = r + 1;
		int ans = max(len1,len2);
		p1(ans);
	}
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