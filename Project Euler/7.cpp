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

#define MAXM 1000000
void solve() {

    vi sieve(MAXM,1);
    sieve[0] = sieve[1] = 0;
    ll cnt = 0;

    for(ll i = 2 ; i < MAXM ; i++) {
    	if(sieve[i]) {
    		cnt++;
    		for(int j = 2 ; i*j < MAXM ; j++) sieve[i*j] = 0;
    		if(cnt == 10001) {
    			p1(i); return;
    		}
    	}
    }
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