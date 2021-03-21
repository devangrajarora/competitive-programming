#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAXM 200001
/*-------------------------------------------------*/

int main()
{
    fastio;

    int n, num;
    cin >> n;
    
    int pos[n]{0}, sz[n]{0};

    rep(i,n) {
        cin >> num;
        pos[num] = i;
    }

    rep(i,n) {
        cin >> num;
        int shifts = pos[num] - i;
        if(shifts < 0) {
            shifts += n;
        }

        sz[shifts]++;
    }

    int ans = INT_MIN;
    for(auto it : sz) { 
        ans = max(ans, it);
    }

    cout << ans << "\n";
    return 0;
}