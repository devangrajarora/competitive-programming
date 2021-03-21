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
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

/*-------------------------------------------------*/

ll highestPowerof2(ll n) 
{ 
    ll res = 0; 
    for (ll i=n; i>=1; i--) 
    { 
        if ((i & (i-1)) == 0) 
        { 
            res = i; 
            break; 
        } 
    } 
    return res; 
} 



bool powerOfTwo(ll n) {
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

void solve() {

	ll n;
	cin >> n;

	if(n == 1 || n == 4) {
		p1("FastestFinger");
		return;
	}

	if(n == 2) {
		p1("Ashishgup");
		return;
	}


        if(n%2==1) {
            p1("Ashishgup");
        }
        else
        {
            if((n%4 != 0 && isPrime(n/2))) {
                p1("FastestFinger");
            } else if(powerOfTwo(n) && n != 2) {
				p1("FastestFinger");
            }  else {
                p1("Ashishgup");
            }
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