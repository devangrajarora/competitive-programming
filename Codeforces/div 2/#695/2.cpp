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

ll n;

bool isHill(vi &a, int i) {
	return i-1 >= 0 and a[i] > a[i-1] and i+1 < n and a[i] > a[i+1];
}

bool isValley(vi &a, int i) {
	return i-1 >= 0 and a[i] < a[i-1] and i+1 < n and a[i] < a[i+1];
}

bool isValleyOrHill(vi &a, int i) {
	return isValley(a,i) or isHill(a,i);
}

void solve() {

	ll total = 0;
	cin >> n;
	vi a(n);
	rep(i,n) cin >> a[i];

	vi is(n,0);

	repb(i,1,n-1) {
		if(isValleyOrHill(a,i)) {
			total++;
			is[i] = 1;
		}
	}  

	ll ans = total;

	repb(i,1,n-1) {
		ll temp = a[i];
		a[i] = a[i-1];
		ll newCnt = total - is[i-1] - is[i] - is[i+1] + isValleyOrHill(a,i-1) + isValleyOrHill(a,i) + isValleyOrHill(a,i+1);
		ans = min(ans, newCnt);

		a[i] = a[i+1];
		newCnt = total - is[i-1] - is[i] - is[i+1] + isValleyOrHill(a,i-1) + isValleyOrHill(a,i) + isValleyOrHill(a,i+1);
		ans = min(ans, newCnt);

		a[i] = temp;
	}

	p1(ans);
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