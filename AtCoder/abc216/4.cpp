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

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a[m], topLevel(n+1);
	vector<int> indices[n+1];
	vector<int> ptr(m);
	int left = n;
	queue<int> q;

	rep(i,m) {
		int k, num; cin >> k;
		ptr[i] = k-1;
		rep(j,k) {
			cin >> num;
			a[i].pb(num);
			indices[num].pb(i);
		}

		topLevel[num]++;
		if(topLevel[num] == 2) {
			q.push(num);
		}
	}


	while(!q.empty()) {
		int num = q.front(); left--;
		q.pop();
		int i1 = indices[num][0], i2 = indices[num][1];
		topLevel[num] = 0;
		if(indices[num][0] == indices[num][1]) {
			p1("No"); return;
		}

		rep(i,2) {
			int r = indices[num][i];
			int c = --ptr[r];
			if(c < 0) continue;
			int newNum = a[r][c];
			topLevel[newNum]++;
			if(topLevel[newNum] == 2) {
				q.push(newNum);
			}
		}
	}

	// p1(left);
	(left == 0) ? p1("Yes") : p1("No");
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