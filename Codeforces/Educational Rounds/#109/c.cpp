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

struct Unit {
	ll pt;
	char dir;
	ll idx;
};

bool comp(Unit &a, Unit &b) {
	return a.pt < b.pt;
}

ll calc(ll L, ll R, ll m) {
	// p3(L,R,m);
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

	// watch(ans);
	return ans;
}

void collide(int a, int b) {
	p3(a,b,"COLLIDE");
}

void solve() {

    ll n, m;
    cin >> n >> m;
    vi ans(n,-1), val(n);
    vector<char> directions(n);
    rep(i,n) cin >> val[i];
    rep(i,n) cin >> directions[i];
    vector<Unit> a(n);

    rep(i,n) {
    	a[i] = {val[i], directions[i], i};
    }

    sort(a.begin(), a.end(), comp);

    stack<pii> oddL, oddR, evenL, evenR;

    rep(i,n) {
    	Unit u = a[i];
    	ll pt = u.pt;
    	char dir = u.dir;
    	ll idx = u.idx;

    	if(pt%2) { // check odds

    		ll R = INT_MAX, L = INT_MAX;
    		pii Rcandidate, Lcandidate;

    		if(!oddR.empty()) {
    			Rcandidate = oddR.top();
    			ll d = pt - Rcandidate.fi;
    			R = (dir == 'L') ? d/2 : m-pt + d/2; 
    		}

			if(!oddL.empty()) {
    			Lcandidate = oddL.top();
    			ll d = pt - Lcandidate.fi;
    			L = (dir == 'L') ? Lcandidate.fi + d/2 : calc(Lcandidate.fi,pt,m); // not ok
    		}

    		if(L == INT_MAX and R == INT_MAX) {
    			if(dir == 'R') oddR.push({pt,idx});
    			else oddL.push({pt,idx});

    		} else if(R < L) {
    			collide(Rcandidate.se,idx);
    			ans[Rcandidate.se] = ans[idx] = R;
    			oddR.pop();
    		} else {
    			collide(Lcandidate.se,idx);
    			ans[Lcandidate.se] = ans[idx] = L;
    			oddL.pop();
    		}

    	} else {

    		ll R = INT_MAX, L = INT_MAX;
    		pii Rcandidate, Lcandidate;

    		if(!evenR.empty()) {
    			Rcandidate = evenR.top();
    			ll d = pt - Rcandidate.fi;
    			R = (dir == 'L') ? d/2 : m-pt + d/2;
    		}

			if(!evenL.empty()) {
    			Lcandidate = evenL.top();
    			ll d = pt - Lcandidate.fi;
    			L = (dir == 'L') ? Lcandidate.fi + d/2 : calc(Lcandidate.fi,pt,m); // not ok
    		}

    		if(L == INT_MAX and R == INT_MAX) {
    			if(dir == 'R') evenR.push({pt,idx});
    			else evenL.push({pt,idx});
    			
    		} else if(R < L) {
    			collide(Rcandidate.se,idx);
    			ans[Rcandidate.se] = ans[idx] = R;
    			evenR.pop();
    		} else {
    			collide(Lcandidate.se,idx);
    			ans[Lcandidate.se] = ans[idx] = L;
    			evenL.pop();
    		}
    	}
    }

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