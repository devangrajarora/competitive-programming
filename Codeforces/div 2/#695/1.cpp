#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
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

// read once, read again, think, code

void solve() {

	ll n, num = 9;
	cin >> n;
	bool decreasing = true;
	string ans = "";

	if(n == 1) {
		p1(9);
	} else if(n == 2) {
		p1(98);
	} else if(n == 3) {
		p1(989);
	} else {
		string ans = "989";
		int num = 0;
		repb(i,3,n) {
			ans += to_string(num);
			num = (num + 1) % 10;
		}
		p1(ans);
	} 

}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    w(tc)
    	solve();
	
	return 0;
}