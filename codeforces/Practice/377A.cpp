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
#define popb pop_back()
#define endl "\n"
#define pii pair < long long, long long >
typedef priority_queue<ll, vector<ll>, greater<ll>> minheap;
typedef priority_queue<ll> maxheap;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
#define sortv(v) sort(v.begin(),v.end())
#define rsortv(v) sort(v.begin(),v.end(), greater<>());
#define sortby(v,prop) sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop < rhs.prop; });
#define rsortby(v,prop) sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop > rhs.prop; });

ll modPower(ll num,ll r){
	if(r==0) return 1;
	if(r==1) return num%MOD;
	ll ans=modPower(num,r/2)%MOD;
	if(r%2==0) {
		return (ans*ans)%MOD;
	} return (((ans*ans)%MOD)*num)%MOD;
}

/*-------------------------------------------------*/
#define vb vector<bool>
#define vvb vector<vb>

ll n, m, k, rem;

int dr4[] = {0,1,0,-1};
int dc4[] = {1,0,-1,0};

bool safe(int x, int y) {
	return (0<=x && x < n && y >= 0 && y < m);
}

void dfs(vector<string> &a, vvb &vis, int x, int y) {
	
	if(!rem) return;
	vis[x][y] = true;
	rem--;
	if(!rem) return;

	rep(i,4) {
		int nx = x + dr4[i];
		int ny = y + dc4[i];
		if(safe(nx,ny) && !vis[nx][ny] && a[nx][ny] == '.') {
			dfs(a,vis,nx,ny);
		}
	}
}

void solve() {

	cin >> n >> m >> k;
	
	int s = 0;
	vector<string> a(n);
	
	rep(i,n) {
		cin >> a[i];
		rep(j,m) {
			if(a[i][j] == '.') s++;
		}
	}

	rem = s-k;

	vvb vis(n,vb(m,false));
	bool f = false;

	rep(i,n) {
		rep(j,m) {
			if(a[i][j] == '.') {
				dfs(a,vis,i,j);
				f = true;
				break;
			}
		}
		if(f) break;
	}

	rep(i,n) {
		rep(j,m) {
			if(!vis[i][j] && a[i][j] == '.') {
				a[i][j] = 'X';
			}
		}

		p1(a[i]);
	}
}


int main()
{
	fastio;
	solve();
	return 0;
}