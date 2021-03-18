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
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl

/*-------------------------------------------------*/

void cases(int tc) {
	cout << "Case #" << tc << ": ";
}

void solve(int tc) {

	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	
	ll exA = a-c, exB = b-c;

	if(exA+exB+c > n) {
		cases(tc);
		p1("IMPOSSIBLE");
		return;
	}

	vector<ll> arr(n,1);
	rep(i,exA) arr[i] = n-1;
	rep(i,exB) arr[n-1-i] = n-1;
	rep(i,c) arr[i+exA] = n;
	

	ll lmax = INT_MIN, rmax = INT_MIN, lcnt = 0, rcnt = 0;

	if(exB == 0) {
		int l = exA, h = n-1;
		if(exA == 0) l++;
		if(arr[l] == n && arr[h] == 1) {
		    swap(arr[l],arr[h]);
		}
	}

	rep(i,n) {
		lmax = max(lmax,arr[i]);
		rmax = max(rmax,arr[n-i-1]);
		if(arr[i] == lmax) lcnt++;
		if(arr[n-i-1] == rmax) rcnt++;
		
	}


	if(lcnt != a || rcnt != b) {
		cases(tc);
		p1("IMPOSSIBLE");
		return;
	}

	cases(tc);
	rep(i,n) p0(arr[i]);
	cout << "\n";
}


int main()
{
	fastio;
	int tc,x = 1;
	cin >> tc;

	while(tc--)	{
		solve(x++);
	}

	return 0;
}