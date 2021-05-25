#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD = 1000000007;
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

ll n, m;

struct Unit {
    ll pt;
    char dir;
    ll idx;
};

bool comp(Unit &a, Unit &b) {
    return a.pt < b.pt;
}

ll calc(ll L, ll R) {
    ll distToReachLeft = L, distToReachRight = m-R, ans;
    if(distToReachLeft < distToReachRight) {
        R += distToReachLeft;
        L = 0;
        ans = distToReachLeft + (m-R) + (R-L)/2;
    } else {
        L -= distToReachRight;
        R = m;
        ans = distToReachRight + L + (R-L)/2;
    }

    return ans;
}

void func(vector<Unit> &a, vi &ans) {
    stack<Unit> right;
    queue<Unit> left;

    for(auto &u : a) {
        ll pt = u.pt, idx = u.idx;
        char dir = u.dir;
        if(dir == 'R') {
            right.push(u);
        } else {
            if(right.empty()) {
                left.push(u);
            } else {
                ll d = (pt - right.top().pt)/2;
                ans[right.top().idx] = ans[u.idx] = d;
                right.pop();
            }
        }
    }

    while(right.size() >= 2) {
        Unit one = right.top(); right.pop(); 
        Unit two = right.top(); right.pop();
        ll d = (one.pt - two.pt) / 2 + (m-one.pt);
        ans[one.idx] = ans[two.idx] = d;  
    }

    while(left.size() >= 2) {
        Unit one = left.front(); left.pop(); 
        Unit two = left.front(); left.pop();
        ll d = (two.pt - one.pt) / 2 + (one.pt);
        ans[one.idx] = ans[two.idx] = d;  
    }

    if(left.size() == 1 and right.size() == 1) {
        ll d = calc(left.front().pt, right.top().pt);
        ans[left.front().idx] = ans[right.top().idx] = d;
    }
}

void solve() {

    cin >> n >> m;
    vi ans(n,-1), val(n);
    vector<char> directions(n);
    rep(i,n) cin >> val[i];
    rep(i,n) cin >> directions[i];

    vector<Unit> odd, even;

    rep(i,n) {
        if(val[i]%2) odd.pb({val[i], directions[i], i});
        else even.pb({val[i], directions[i], i});
    }

    sort(odd.begin(), odd.end(), comp);
    sort(even.begin(), even.end(), comp);

    func(odd, ans);
    func(even,ans);

    p1(ans);
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