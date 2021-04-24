#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vi>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl

/*-------------------------------------------------*/

// read once, read again, think, code

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

    // n starts from 0
    ll n; cin >> n;
    
    if(n <= 1) {
        p1(n); return;
    }

    vvi a(2, vi(2,1));
    a[1][1] = 0;

    vvi mul = matrixPower(a,n-1);
    ll ans = mul[0][0] % MOD;
    p1(ans);
}


int main()
{
    fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    solve();
    
    return 0;
}