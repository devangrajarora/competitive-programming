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

int ans = INT_MIN;

bool checkSorted(vi &a, int l, int r) {
	rep(i,l,r-1) {
		if(a[i] > a[i+1]) return false;
	} return true;
}

void func(vi &a, int l, int r) {
	if(l > r) return;
	// p2(l,r);
	int mid = (r-l)/2;
	if(checkSorted(a,l,r)) {
		ans = max(ans,r-l+1); return;
	}
	
	func(a,l,l+mid);
	func(a,l+mid+1,r);
}

void solve() {

	int n; cin >> n;
	vi a(n);
	rep(i,0,n-1) cin >> a[i];    
	func(a,0,n-1);
	p1(ans);
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