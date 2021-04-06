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

void solve() {

	ll n, i = 0, ans = 0; cin >> n;
	string s; cin >> s;    
	unordered_map<char, int> m; 
	char opt[] = {'R', 'B', 'G'};
	m['R'] = 0;
	m['B'] = 1;
	m['G'] = 2;

	while(i < n-1) {

		char c = s[i];

		if(i < n-2 and s[i] == s[i+1] and s[i] and s[i+1] == s[i+2]) {
			ans++;
			s[i+1] = (s[i] == 'R') ? 'B' : (s[i] == 'B') ? 'G' : 'R';

		} else if(s[i] == s[i+1]) {
			ans++;
			if(i == n-2) s[i+1] = (s[i] == 'R') ? 'B' : (s[i] == 'B') ? 'G' : 'R';
			else s[i+1] = opt[3 ^ m[s[i]] ^ m[s[i+2]]];

		}
		
		i++;
		
	}

	p1(ans);
	p1(s);
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