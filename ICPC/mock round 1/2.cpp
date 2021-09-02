#include<bits/stdc++.h>
using namespace std;

void solve() {

    ll n; cin >> n;
	ll ans = 1 + n%9;
	p1(ans);
}


int main()
{

    #ifndef ONLINE_JUDGE
	freopen("/home/devang/input.txt","r",stdin);
	freopen("/home/devang/output.txt","w",stdout);
    #endif

    solve();
	
	return 0;
}
