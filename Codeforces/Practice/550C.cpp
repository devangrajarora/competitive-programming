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

    string s;
    cin >> s;
    int n = s.size();
    rep(i,0,n-1) {
    	if(s[i] == '0') {p1("YES"); p1("0"); return;}
    	if(s[i] == '8') {p1("YES"); p1("8"); return;}
    }

    if(n <= 2) {
    	int num = stoi(s);
    	if(num%8==0) {
    		p1("YES"); p1(s); return;
    	} else {
    		p1("NO"); return;
    	}
    }

    rep(i,0,n-2) {
    	rep(j,i+1,n-1) {
			int num = (s[i]-'0')*10 + (s[j]-'0');
			if(num%8==0) {
				string ans = to_string(num);
				p1("YES"); p1(ans); return;
			}
		}
    	
    }

    rep(i,0,n-3) {
    	rep(j,i+1,n-2) {
    		rep(k,j+1,n-1) {
    			int num = (s[i]-'0')*100 + (s[j]-'0')*10 + (s[k]-'0');
    			if(num%8==0) {
    				string ans = s.substr(0,i) + to_string(num);
    				p1("YES"); p1(ans); return;
    			}
    		}
    	}
    }

    p1("NO");
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