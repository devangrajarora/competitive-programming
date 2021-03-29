#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define endl "\n"
#define vi vector<ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define w(x)  ll x; cin>>x; while(x--)

/*-------------------------------------------------*/

// read once, read again, think, code

void solve() {

	// Sum of n terms in AP	n/2[2a + (n – 1)d]
	ll n3 = 999 / 3, n5 = 999 / 5, n15 = 999 / 15; 
	ll sumAP3 = n3 * (2*3 + (n3-1)*3) / 2; 
	ll sumAP5 = n5 * (2*5 + (n5-1)*5) / 2; 
	ll sumAP15 = n15 * (2*15 + (n15-1)*15) / 2; 
	ll ans = sumAP3 + sumAP5- sumAP15;
	p1(ans);
}

void solve2() {

	ll ans = 0;
	rep(i,1,999) {
		if(i%3==0 or i%5==0) {
			ans += i;
		}
	} p1(ans);
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