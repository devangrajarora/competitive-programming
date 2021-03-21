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

ll modPower(ll num,ll r){
	if(r==0) return 1;
	if(r==1) return num%MOD;
	ll ans=modPower(num,r/2)%MOD;
	if(r%2==0) {
		return (ans*ans)%MOD;
	} return (((ans*ans)%MOD)*num)%MOD;
}

/*-------------------------------------------------*/

void solve() {

	string s;
	cin >> s;
	int n = s.size();

	int num;
	rep(i,n) {
		num = (s[i]-'0');
		if(num%8==0) {
			p1("YES");
			p1(num);
			return;
		}
		repb(j,i+1,n) {

			num = (s[i]-'0')*10 + (s[j]-'0');
			if(num%8==0) {
				p1("YES");
				p1(num);
				return;
			}

			repb(k,j+1,n) {
				num = (s[i]-'0')*100 + (s[j]-'0')*10 + (s[k]-'0');
				if(num%8==0) {
					p1("YES");
					p1(num);
					return;
				}
			}			
		}
	}

	p1("NO");
}


int main()
{
	fastio;
	solve();
	return 0;
}