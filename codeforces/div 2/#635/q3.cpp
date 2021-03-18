#include<bits/stdc++.h>
#define ll long long int 
#define MOD 1000000007
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define repe(i,n) for(int i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(int i = a ; i < b ; i++)
#define repeb(i,a,b) for(int i = a ; i <= b ; i++)
#define pb push_back
#define newLine cout << "\n"
#define endl "\n"
#define pii pair<int,int> 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

unordered_map<int,int> m;

class Node
{
public:
	int node;
	int level;
};

unordered_map<int,int> kidscnt;
unordered_set<int> st;

void bfs(vector<int> *adj, int n, int k, bool *visited, int *sz) {

	stack<Node> s;
	queue<Node> q;
	q.push({1,0});


	while(!q.empty()) {

		Node curr = q.front();
		q.pop();
		m[curr.level]++;
		visited[curr.node] = true;
		s.push(curr);
		
		for(auto i : adj[curr.node]) {
			if(visited[i] == false) {
				q.push({i,curr.level+1});
			}
		}

	}

	ll ans = 0;
	vector<pii> v;

	while(!s.empty()) {

		Node curr = s.top();
		s.pop();
		st.insert(curr.node);
		kidscnt[curr.node] = sz[curr.node];

		for(auto it : adj[curr.node]) {
			if(st.find(it) != st.end()) {
				kidscnt[curr.node] += kidscnt[it];
			}
		}

		ll addn = curr.level - kidscnt[curr.node];

		ans += addn;
		v.pb({curr.node,addn});
	}

	sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){
   		return lhs.second > rhs.second;
	});

	rep(i,k) {
		ans += v[i].second;
	}

	cout << ans;

}

int main()
{
	fastio;

	int n, k;
	cin >> n >> k;

	int *sz = new int[n + 1];
	bool *visited = new bool[n + 1];

	repe(i,n) {
		sz[i] = -1;
		visited[i] = false;
	}

	vector<int> adj[n + 1];

	rep(i,n-1) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
		sz[x]++;
		sz[y]++;
	}

	sz[1]++;


	bfs(adj,n,k,visited,sz);
	return 0;
}


/*
9 6
1 2   
2 3
3 4
3 5
3 7
5 6
7 8
7 9
*/