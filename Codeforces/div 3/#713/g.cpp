#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define vi vector<ll>

const ll MAXM  = 10000001;
vi sum(MAXM,0);
vector<int> c(MAXM, 0);

void sieve() {

    for(ll i = 1 ; i < MAXM ; i++) {

        for(ll j = i ; j < MAXM  ; j += i) {
            sum[j] += i;
        }

        if(sum[i] < MAXM) {
            if(c[sum[i]] == 0) {
                c[sum[i]] = i; 
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif
    while(1);
    sieve();

    int tc; cin >> tc;

    while(tc--) {
        ll n;
        cin >> n;
        if(c[n] == 0) cout << -1 << "\n";
        else cout << c[n] << "\n";
    }

    return 0;
}