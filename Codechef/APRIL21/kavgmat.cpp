#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define se second
#define loop(i,a,b) for(ll i = a ; i <= b ; i++)
#define endl "\n"
#define vi vector<ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define w(x)  ll x; cin>>x; while(x--)

void solve() {

    ll n,m,k,ans = 0;
    cin >> n >> m >> k;
    vector<vi> psa(n+1, vi(m+1));
    loop(i,0,n) psa[i][0] = 0;
    loop(i,0,m) psa[0][i] = 0;

    loop(i,1,n) {
    	loop(j,1,m) {
    		cin >> psa[i][j];
    		ans += (psa[i][j] >= k);
    		psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
    	}
    }

    loop(i,1,n) {
    	loop(j,1,m) {
    		ll l = 1;
    		while(i+l <= n and j+l <= m) {
    			ll x = i+l, y = j+l;
    			ll num = (l+1)*(l+1);
    			ll total = psa[x][y] - psa[x][j-1] - psa[i-1][y] + psa[i-1][j-1];
    			if(total*1.0/num >= k) ans += 1;
    			l += 1;
    		}
    	}
    }

    cout << ans << "\n";
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

    w(tc)
    	solve();
	
	return 0;
}