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
#define vi vector<ld>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
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
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }
    
/*-------------------------------------------------*/

// read once, read again, think, code

// constant space dp

/*
	double prevHappy = 1, prevSad = 0;

	for(int i = 0 ; i < n ; i++) {
		double currHappy = prevHappy * (1-p) + prevSad * p;
		double currSad = prevSad * (1-p) + prevHappy * p;
		prevHappy = currHappy; prevSad = currSad;
	}
*/

vvi multiply2x2(vvi &a, vvi &b) {
    vvi c(2, vi(2,0));
    for(int i = 0 ; i < 2 ; i++) {
        for(int j = 0 ; j < 2 ; j++) {
            for(int k = 0 ; k < 2 ; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}

vvi matrixPower(vvi &a, ll n) {
    if(n == 1) return a;
    vvi smallMatrix = matrixPower(a,n/2);
    vvi result = multiply2x2(smallMatrix, smallMatrix);
    if(n%2) {
        result = multiply2x2(result, a);
    }

    return result;
}

void solve() {

	ll n;
	ld p;
	cin >> n >> p;
    
	double prevHappy = 1, prevSad = 0;

	vvi a(2, vi(2));
    a[0][0] = a[1][1] = 1-p;
    a[0][1] = a[1][0] = p;

    vvi resultMatrix = matrixPower(a,n);
    ld finalHappy =  resultMatrix[0][0];

	cout << fixed << setprecision(12) << finalHappy;
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