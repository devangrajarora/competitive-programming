#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define repe(i,n) for(int i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(int i = a ; i < b ; i++)
#define repeb(i,a,b) for(int i = a ; i <= b ; i++)
#define rfor(i,n,a) for(int i = n ; i >= a ; i--)
#define pb push_back
#define popb pop_back()
#define endl "\n"
#define pii pair<int,int> 
#define pll pair < long long, long long >
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

ll n, m;
bool visited[51][51];
char mat[51][51];

bool check(int i, int j) {
	return (i < n && j < m && i >= 0 && j >= 0);
}

bool isValid(int i, int j) {
	return (i < n && j < m && i >= 0 && j >= 0 && (mat[i][j] == '.' || mat[i][j] == 'G'));
}

int dx[4]{1,0,-1,0};
int dy[4]{0,1,0,-1};

bool dfs(int x, int y) {

	if(x == n - 1 && y == m - 1) {
		return true;
	}

	visited[x][y] = true;

	rep(i,4) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if(isValid(newX,newY) && !visited[newX][newY]) {
			if(dfs(newX,newY)) {
				return true;
			}
		}
	}

	return false;
}

void solve() {

	ll good = 0, bad = 0;
	cin >> n >> m;

	rep(i,n) {
		rep(j,m) {
			cin >> mat[i][j];
			if(mat[i][j] == 'G') {
				good++;
			}
			if(mat[i][j] == 'B') {
				bad++;
			}
		}
	}

	if(mat[n-1][m-1] == '#') {
		if(good == 0) {
			p1("Yes");
		} else {
			p1("No");
		}
		return;
	}

	if(good == 0) {
		p1("Yes");
		return;
	}

	rep(i,n) {
		rep(j,m) {
			if(mat[i][j] == 'B') {

				rep(k,4) {
					int x = i + dx[k];
					int y = j + dy[k];
				
					if(check(x,y)) {

						if(mat[x][y] == 'G') {
							p1("No");
							return;
						} else if(mat[x][y] != 'B'){
							mat[x][y] = '#';
						}
					}
				}	
			}
		}
	}

	rep(i,n) {
		rep(j,m) {
			if(mat[i][j] == 'G') {
				memset(visited,false,sizeof(visited));
				bool ans = dfs(i,j);
				if(!ans) {
					p1("No");
					return;
				}
			}
		}
	}

	p1("Yes");
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