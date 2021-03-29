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
#define pii pair<ll,ll>

/*-------------------------------------------------*/

// read once, read again, think, code

bool isPalin(ll num) {
	string s = to_string(num);
	int l = 0, r = s.size()-1;
	while(l <= r) {
		if(s[l++] != s[r--]) return false;
	} return true;
}

void solve() {

   	queue<pii> q; q.push({999,999});
   	map<pii,ll> m; 
   	while(true) {
   		pii curr = q.front();
   		q.pop();
   		if(m[curr] > 0) continue;
   		m[curr]++;
   		ll num = curr.fi * curr.se;
   		if(isPalin(num)) {
   			p1(num); return;
   		}

   		q.push({curr.fi-1,curr.se});
   		q.push({curr.fi,curr.se-1});
   	}
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