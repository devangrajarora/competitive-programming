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

ll modPower(ll num,ll r) {
	if(r==0) return 1;
	if(r==1) return num%MOD;
	ll ans=modPower(num,r/2)%MOD;
	if(r%2==0) {
		return (ans*ans)%MOD;
	} return (((ans*ans)%MOD)*num)%MOD;
}

ll nCr(ll n, ll r) { 
	ll res = 1; 
	if (r > n - r) {
		r = n - r; 
	}
	rep(i,r) { 
		res *= (n - i); 
		res /= (i + 1); 
	} 
	return res; 
}

bool isPrime(long long n)
{
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

		return true;
	}


/*-------------------------------------------------*/

	void solve() {

		ll n, k;
		cin >> n >> k;

		if(k == 0) {
			p1(0);
			rep(i,n) {
				rep(j,n) {
					cout << 0;
				}cout << "\n";
			}
			return;
		}

		if(k == n*n) {
			p1(0);
			rep(i,n) {
				rep(j,n) {
					cout << 1;
				}cout << "\n";
			}
			return;
		}

		ll zeroes = n*n - k;
		ll x = ceil((zeroes*1.0) / k);
		ll y = zeroes / k;

		ll ans = 2*(y-x)*(y-x);
		p1(ans); 

	// x -> max zeroes in a row or column
	// y -> min zeroes in a row or column

		int a[n][n];
		memset(a,0,sizeof(a));

		ll done = 0;

		rep(i,n) {
			rep(j,n) {
				if(done == k) {
					break;
				}
				if(i % 2 == 0) {
					if(j%2==0) {
						a[i][j] = 1;
						done++;
					}
				} else {
					if(j%2==1) {
						a[i][j] = 1;
						done++;
					}

				}
			}
		if(done == k) {
			break;
		}
	}

	if(done != k) {

		rep(i,n) {
			rep(j,n) {
				if(done == k) {
					break;
				}
				if(i % 2 == 0) {
					if(j%2==1) {
						a[i][j] = 1;
						done++;
					}
				} else {
					if(j%2==0) {
						a[i][j] = 1;
						done++;
					}

				}
			}
			if(done == k) {
				break;
			}
		}
	}




	rep(i,n) {
		rep(j,n) {
			cout << a[i][j];
		}cout << "\n";
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