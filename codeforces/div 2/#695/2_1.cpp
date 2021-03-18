#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i <= b ; i++)
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

	ll n;
	cin >> n;
	vi a(n);
	rep(i,n) cin >> a[i];	 
	ll total = 0, pts3 = 0, pts4 = 0, pts5 = 0;
	repb(i,1,n-2) {
		if(a[i-1] < a[i] and a[i+1] < a[i]) pts3++;
		if(a[i-1] > a[i] and a[i+1] > a[i]) pts3++;

		if(i < n-2 and a[i] < a[i-1] and a[i] < a[i+1] and a[i+2] < a[i+1]) pts4++;
		if(i < n-2 and a[i] > a[i-1] and a[i] > a[i+1] and a[i+2] > a[i+1]) pts4++;

		if(i < n-3 and a[i] < a[i-1] and a[i] < a[i+1] and a[i+2] < a[i+1] and a[i+2] < a[i+3]) pts5++;
		if(i < n-3 and a[i] > a[i-1] and a[i] > a[i+1] and a[i+2] > a[i+1] and a[i+2] > a[i+3]) pts5++;
	}  


	if(pts5) {
		p1(pts3-3);
	} else if(pts4) {
		p1(pts3-2);
	} else if(pts3) {
		p1(pts3-1);
	} else {
		p1(pts3);
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