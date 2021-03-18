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

int main()
{
	fastio;
	int tc;
	cin >> tc;

	while(tc--)
	{
		int x, n, m, flag = 0;
		cin >> x >> n >> m;

		while(n--) {
			
			if( x <= 20) {
				break;
			}

			x = (x / 2) + 10;

			if(x <= 0) {
				flag = 1;
				break;
			}
		}

		if(x - 10 * m <= 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}