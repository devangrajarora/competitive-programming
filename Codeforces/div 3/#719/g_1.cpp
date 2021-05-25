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

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
    
/*-------------------------------------------------*/

// read once, read again, think, code

#define vb vector<bool>

ll n, m, w;

bool valid(ll i, ll j) {
	return 0 <= i and i < n and 0 <= j and j < m;
}

void bfs(vvi &a, int si, int sj, vvi &d) {
    
    d[si][sj] = 0;

    queue<pii> q;
    q.push({si,sj});

    while(!q.empty()) {
        pii curr = q.front();
        q.pop();
        rep(i,4) {
            int ni = curr.fi + dr4[i];
            int nj = curr.se + dc4[i];
            if(valid(ni,nj) and a[ni][nj] != -1 and d[ni][nj] == -1) {
                d[ni][nj] = 1 + d[curr.fi][curr.se];
                q.push({ni,nj});
            }
        }
    }
}

void solve() {

    cin >> n >> m >> w;
    vvi a(n, vi(m));

    rep(i,n) {
    	rep(j,m) {
    		cin >> a[i][j];
    	}
    }

    vvi d1(n, vi(m,-1));
    vvi d2(n, vi(m,-1));


    bfs(a,0,0,d1);
    bfs(a,n-1,m-1,d2);


    ll onePortalUse = LLONG_MAX, closestPortalToEnd = LLONG_MAX;
    ll noPortalUse = (d1[n-1][m-1] == -1) ? LLONG_MAX : w*d1[n-1][m-1]; 

    rep(i,n) {
        rep(j,m) {
            if(a[i][j] > 0 and d2[i][j] != -1) {
                closestPortalToEnd = min(closestPortalToEnd, w*d2[i][j] + a[i][j]);
            }
        }
    }


    if(closestPortalToEnd != LLONG_MAX) {
        rep(i,n) {
            rep(j,m) {
                if(a[i][j] > 0 and d1[i][j] != -1) {
                    onePortalUse = min(onePortalUse, d1[i][j]*w + a[i][j] + closestPortalToEnd);
                }
            }
        }
    }


    ll ans = min(noPortalUse, onePortalUse);
    if(ans == LLONG_MAX) ans = -1;
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