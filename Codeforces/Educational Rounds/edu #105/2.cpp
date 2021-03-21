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
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
#define w(x) ll x; cin>>x; while(x--)

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code

bool solve() {

	int n, u, r, d, l;
	cin >> n >> u >> r >> d >> l;

	int u1 = u, r1 = r, d1 = d, l1 = l;

	if(u == n) r1--, l1--;
	if(u == n-1) (r1 > l1) ? r1-- : l1--;

	if(r == n) u1--, d1--;
	if(r == n-1) (u1 > d1) ? u1-- : d1--;

	if(d == n) r1--, l1--;
	if(d == n-1) (r1 > l1) ? r1-- : l1--;

	if(l == n) u1--, d1--;
	if(l == n-1) (u1 > d1) ? u1-- : d1--;

	int MIN = min({u1,l1,r1,d1});
	if(MIN < 0) return 0;
	return 1;
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif

	w(tc)
	(solve()) ? p1("YES") : p1("NO");
	
	return 0;
}