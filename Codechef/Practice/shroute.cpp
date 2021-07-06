#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

ll modPower(ll num,ll r) {
    if(r==0) return 1;
    if(r==1) return num%MOD;
    ll ans=modPower(num,r/2)%MOD;
    if(r%2==0) {
        return (ans*ans)%MOD;
    } return (((ans*ans)%MOD)*num)%MOD;
}


void solve() {

    ll n,m; cin >> n >> m;
    ll ans = modPower((modPower(2,n)-1),m);
    cout << ans << "\n";
}

int main()
{

    #ifndef ONLINE_JUDGE
	freopen("/home/devang/input.txt","r",stdin);
	freopen("/home/devang/output.txt","w",stdout);
    #endif

	int tc; cin >> tc; 
	for(int i = 0 ; i < tc ; i++)
    	solve();
	
	return 0;
}

unordered_map<ll, ll> m;
m.reserve(1<<10);
m.max_load_factor(0.25);