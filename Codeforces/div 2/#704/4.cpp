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

	ll z, o, k;
	cin >> z >> o >> k;
    ll n = z+o;

	string one(n,'0');
	string two(n,'0'); 
    
	if(z == 0) {
		if(k == 0) p1("YES"),p1(string(n,'1')), p1(string(n,'1'));				
		else p1("NO");
		return;
	}

	o--;
    one[0] = '1', two[0] = '1';

    if(o == 0) {
    	if(k == 0) p1("YES"), p1(one), p1(two);
    	else p1("NO");
		return;
    }

    if(k > z+o-1) {
		p1("NO");
		return;
	}
	
	two[n-1] = '1';
	ll idx = n-1-k;
	one[idx] = '1';
	o--, z--;
	repb(i,1,n-2) {
		if(i == idx) continue;
		if(o) one[i] = two[i] = '1', o--;
		else if(z) one[i] = two[i] = '0', z--;
	}

	p1("YES");
	p1(one);
	p1(two);	
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    solve();
	
	return 0;
}