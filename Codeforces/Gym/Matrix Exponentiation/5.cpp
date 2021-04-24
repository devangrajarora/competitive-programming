#include<bits/stdc++.h>
using namespace std;
#define ll unsigned int
#define ld long double
#define MOD 4294967296
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

const int N = 65;

struct Matrix {
	
	vvi a = vvi(N, vi(N));

	Matrix operator *(const Matrix &second) {
		Matrix product;
		rep(i,N) rep(j,N) rep(k,N) {
			product.a[i][j] =  (product.a[i][j] + ((a[i][k] * second.a[k][j]) % MOD) ) % MOD;
		}

		return product;
	}
};

Matrix matrix_expo(Matrix a, ll k) {
	Matrix result;
	rep(i,N) result.a[i][i] = 1; // identity matrix
	while(k > 0) {
		if(k%2) result = result * a;
		a = a * a;
		k /= 2;
	}

	return result;
}

bool valid(ll r, ll c) {
	return 0 <= r and r < 8 and 0 <= c and c < 8;
}

void solve() {
	
	ll k, ans = 0;
	
	cin >> k;

	Matrix board;

	rep(row,8) {
		rep(col,8) {
			for(int dr : {2,-2,1,-1}) {
				for(int dc : {2,-2,1,-1}) {
					if(abs(dr) == abs(dc)) continue;
					int new_row = row + dr;
					int new_col = col + dc;
					if(valid(new_row, new_col)) {
						board.a[row*8+col][new_row*8+new_col] = 1;
					}
				}
			}
		}
	}

	repe(i,64) board.a[i][64] = 1;
	

	Matrix res = matrix_expo(board,k+1);

	// k+1 because in step k+1 we will sum up values from 0...k

	p1(res.a[0][64]);
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