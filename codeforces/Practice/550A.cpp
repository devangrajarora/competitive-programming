#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define pb push_back
#define popb pop_back()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl

/*-------------------------------------------------*/

bool solve() {

	string str;
	cin >> str;
	int n = str.size();
	int aba = 0, ab = 0, ba = 0;
	for(int i = 0 ; i < n - 1 ; i++) {
		if(i < n-2 && (str.substr(i,3) == "ABA" || str.substr(i,3) == "BAB")) {
			aba++;
			i += 2;
		} else if(str.substr(i,2) == "AB") {
			ab++;
		} else if(str.substr(i,2) == "BA") {
			ba++;
		}
	}

	return (aba > 1) || (aba && ab) || (aba && ba) || (ab && ba);
}


int main()
{
	fastio;
	solve() ? p1("YES") : p1("NO");
	return 0;
}