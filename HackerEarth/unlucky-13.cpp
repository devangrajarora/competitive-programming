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
    #define vi vector<int>
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

void solveDP() {

    int n; cin >> n;
    int prev0 = 1, prev1 = 9;

    for(int i = 1 ; i < n ; i++) {
        int new0 = (prev0 + prev1) % MOD;
        int new1 =  ((prev0 * 8) % MOD + (prev1 * 9) % MOD) % MOD;
        prev0 = new0, prev1 = new1;
    }
    

    // dp[i][0] -> good strings ending with 1
    // dp[i][1] -> good strings not ending with 1

    cout << (prev0 + prev1) % MOD << "\n";
}

vvi multiply2x2(vvi &a, vvi &b) {
    vvi c(2, vi(2,0));
    for(int i = 0 ; i < 2 ; i++) {
        for(int j = 0 ; j < 2 ; j++) {
            for(int k = 0 ; k < 2 ; k++) {
                c[i][j] = ( c[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }

    return c;
}

vvi matrixPower(vvi a, ll n) {
    if(n == 1) return a;
    vvi smallMatrix = matrixPower(a,n/2);
    vvi result = multiply2x2(smallMatrix, smallMatrix);
    if(n%2) {
        result = multiply2x2(result, a);
    }

    return result;
}
void solve() {

    int n; cin >> n;

    if(n == 1) {
        p1(10); return;
    }

    if(n == 2) {
        p1(99); return;
    }

    ll one = 10, two = 99;

    vvi a(2,vi(2));
    a[0][0] = a[0][1] = 1;
    a[1][0] = 8; a[1][1] = 9;

    vvi resultMatrix = matrixPower(a,n-1);
    ll endingWith1 = (resultMatrix[0][0] + (9*resultMatrix[0][1]) % MOD) % MOD;
    ll notEndingWith1 = (resultMatrix[1][0] + (9*resultMatrix[1][1])%MOD ) % MOD;

    ll ans = (endingWith1 + notEndingWith1) % MOD;
    cout << ans << "\n";
}


int main()
{
    fastio;
        #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
        #endif

    w(tc)
    solve();

    return 0;
}