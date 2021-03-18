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
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define w(x) ll x; cin>>x; while(x--)

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code

bool areBracketsBalanced(string expr) 
{   
	stack<char> s; 
	char x; 
	for (int i = 0; i < expr.length(); i++)  
	{ 
		if (expr[i] == '(' || expr[i] == '['
			|| expr[i] == '{')  
		{ 
			s.push(expr[i]); 
			continue; 
		} 
		if (s.empty()) 
			return false; 

		switch (expr[i]) { 
			case ')': 

			x = s.top(); 
			s.pop(); 
			if (x == '{' || x == '[') 
				return false; 
			break; 

			case '}': 

			x = s.top(); 
			s.pop(); 
			if (x == '(' || x == '[') 
				return false; 
			break; 

			case ']': 

			x = s.top(); 
			s.pop(); 
			if (x == '(' || x == '{') 
				return false; 
			break; 
		} 
	} 
	
    // Check Empty Stack 
	return (s.empty()); 
} 

void solve() {

	string s;
	cin >> s;
	int n = s.size();
	rep(i,2) {

		rep(j,2) {
			rep(k,2) {
				string temp = s;
				// p3(i,j,k);
				rep(l,n) {
					if(temp[l] == 'A') temp[l] = (i==0) ? '(' : ')';
					else if(temp[l] == 'B') temp[l] = (j==0) ? '(' : ')';
					else if(temp[l] == 'C') temp[l] = (k==0) ? '(' : ')';
				}
				if(areBracketsBalanced(temp)) {
					// p1(temp);
					p1("YES");
					return;
				}
			}
		}

    	// p1(temp);

	}

	p1("NO");
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