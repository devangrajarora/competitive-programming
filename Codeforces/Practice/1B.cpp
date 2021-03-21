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
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl

ll modPower(ll num,ll r) {
	if(r==0) return 1;
	if(r==1) return num%MOD;
	ll ans=modPower(num,r/2)%MOD;
	if(r%2==0) {
		return (ans*ans)%MOD;
	} return (((ans*ans)%MOD)*num)%MOD;
}

/*-------------------------------------------------*/

string conv(int num) {
	string ans = "";
	while(num) {
		ans += (char)(((num-1)%26) + 'A');
		(num) = (num-1)/26;
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

string one(string &s) {

	int rno = 0, cno = 0, i = 1, n = s.size();
	while(s[i] != 'C') {
		rno = rno *10 + (s[i] - '0');
		i++;
	}
	i++;
	while(i < n) {
		cno = cno * 10 + (s[i] - '0');
		i++;
	}
	string ans = conv(cno);
	ans += to_string(rno);
	return ans;
}

bool identifyOne(string &s) {
	if(s[0] != 'R') return false;
	if(s[1] >= 'A' && s[1] <= 'Z') return false;
	for(int i = 2 ; i < s.size() ; i++) {
		if(s[i] == 'C') return true;
	}
	return false;
}

string two(string &s) {
	int n = s.size(), i = 0, colno = 0;
	while(! ('0' <= s[i] && s[i] <= '9')) {
		colno = colno * 26 + ((int)(s[i] - 'A')+1);
		i++;
	}
	string ans = "R" + s.substr(i) + "C" + to_string(colno);
	return ans;
}

void solve() {

	string s;
	cin >> s;
	if(identifyOne(s)) {
		p1(one(s));
	} else {
		p1(two(s));
	}
}


int main()
{
	fastio;
	int tc;
	cin >> tc;

	while(tc--)	{
		solve();
	}

	return 0;
}