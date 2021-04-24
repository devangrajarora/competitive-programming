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
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define w(x) ll x; cin>>x; while(x--)

    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << " ";
            os << v[i];
            first = false;
        }
        return os;
    }
    
/*-------------------------------------------------*/

// read once, read again, think, code

struct Matrix {
	ll a[2][2] = {{0, 0}, {0, 0}};

	Matrix operator *(const Matrix &second) {
		Matrix product;
		rep(i,2) rep(j,2) rep(k,2) {
			product.a[i][j] =  (product.a[i][j] + ((a[i][k] * second.a[k][j]) % MOD) ) % MOD;
		}

		return product;
	}
};

Matrix matrix_expo(Matrix a, ll k) {
	Matrix result;
	rep(i,2) result.a[i][i] = 1; // identity matrix
	while(k > 0) {
		if(k%2) result = result * a;
		a = a * a;
		k /= 2;
	}

	return result;
}

void solve() {

    ll n; cin >> n;

    if(n <= 1) {
        p1(n); return;
    }

    Matrix init;
    init.a[0][0] = 1; init.a[0][1] = 1; 
    init.a[1][0] = 1; init.a[1][1] = 0;


    Matrix res = matrix_expo(init,n-1);
    cout << res.a[0][0];
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