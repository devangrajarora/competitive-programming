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

    ll n, m, hasOne = 0;
    cin >> n >> m;
    vvi b(n, vi(m));
    vi rowSum(n,0), colSum(m,0);
    vi setZeroRow(n,0), setZeroCol(m,0);

    rep(i,n) {
    	rep(j,m) {
    		cin >> b[i][j];
    		rowSum[i] += b[i][j];
    		colSum[j] += b[i][j];
    		if(b[i][j]) hasOne = 1;
    	}
    }

    rep(i,n) {
    	if(rowSum[i] == 0 and hasOne) {
    		p1("NO");
    		return;
    	}
    }

	rep(j,m) {
    	if(colSum[j] == 0 and hasOne) {
    		p1("NO");
    		return;
    	}
    }

    rep(i,n) {
    	rep(j,m) {
    		if(b[i][j]) {
    			if(rowSum[i] < m and colSum[j] < n) {
    				p1("NO");
    				return;
    			}
    		} else {
    			setZeroRow[i] = 1;
    			setZeroCol[j] = 1;
    		}
    	}
    }

    vvi a(n,vi(m,1));

    p1("YES");
    rep(i,n) {
    	rep(j,m) {
    		if(setZeroRow[i] or setZeroCol[j]) a[i][j] = 0;
    	}
    }

    rep(i,n) {
    	rep(j,m) {
    		p0(a[i][j]);
    	} cout << "\n";
    }
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    //w(tc)
    	solve();
	
	return 0;
}