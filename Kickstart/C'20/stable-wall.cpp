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
#define pii pair<int,int> 
#define pll pair < long long, long long >
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

/*-------------------------------------------------*/

void cases(int tc) {
	cout << "Case #" << tc << ": ";
}

void solve(int tc) {

	vector<vector<int>> adj(26);
	unordered_set<char> chars;

	int r,c;
	cin >> r >> c;

	int a[r][c];
	string s;

	rep(i,r) {
		cin >> s;
		rep(j,c) {
			chars.insert(s[j]);
			a[i][j] = s[j] - 'A';
		}
	}

	rep(j,c) {
		rfor(i,r-1,1) {
			if(a[i][j] != a[i-1][j]) {
				adj[a[i][j]].push_back(a[i-1][j]);
			}
		}
	}

	vector<int> indegree(26,0);

	for(auto v : adj) {
		for(auto num : v) {
			indegree[num]++;
		}
	}

	int n = chars.size();
	queue<int> q;
	for(auto c : chars) {
		if(indegree[c-'A'] == 0) {
			q.push(c-'A');
		}
	}

	string ans = "";

	while(!q.empty()) {
		int x = q.front();
		q.pop();

		char c = (char)('A' + x);
		ans += c;

		for(auto num : adj[x]) {
			indegree[num]--;
			if(indegree[num] == 0) {
				q.push(num);
			}
		}
	}

	cases(tc);
	(n == ans.size()) ? p1(ans) : p1(-1);
}


int main()
{
	fastio;
	int tc,x = 1;
	cin >> tc;

	while(tc--)	{
		solve(x++);
	}

	return 0;
}