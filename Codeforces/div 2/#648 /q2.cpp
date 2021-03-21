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


/*-------------------------------------------------*/

class Node
{
public:
	ll num;
	ll type;
	ll index;
};

int main()
{
	fastio;
	int tc;
	cin >> tc;

	while(tc--)
	{
		ll n,x,one = 0,zero = 0,maxi = INT_MIN,elem;
		cin >> n;

		bool sorted = true;

		ll a[n], types[n];
		cin >> maxi;
		
		rep(i,n-1) {
			cin >> elem;
			if(elem >= maxi) {
				maxi = elem;
			} else {
				sorted = false;
			}
		} 

		rep(i,n) {
			cin >> x;
			if(x == 0) {
				zero++;
			} else {
				one++;
			}
		}


		if((zero == 0 || one == 0) && !sorted) {
			p1("No");
		} else {
			p1("Yes");
		}

	}

	return 0;
}