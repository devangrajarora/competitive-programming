#include<bits/stdc++.h>
using namespace std;
#define ll long long
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

void p(vvi &v) {
	for(auto &a : v) {
		for(auto &num : a) {
			p0(num);
		}p1("");
	}
}

void solve() {

	int n, m;
	cin >> n >> m;
	vvi workout(n,vi(m)), boyToMeetingPoint(n,vi(m)), girlToMeetingPoint(n,vi(m));    
	vvi boyToEndPoint(n,vi(m)), girlToEndPoint(n,vi(m));    

	rep(i,n) rep(j,m) cin >> workout[i][j];

	rep(i,n) {
		rep(j,m) {
			if(i == 0 and j == 0) boyToMeetingPoint[i][j] = workout[i][j];
			else if(i == 0) boyToMeetingPoint[i][j] = boyToMeetingPoint[i][j-1] + workout[i][j];
			else if(j == 0) boyToMeetingPoint[i][j] = boyToMeetingPoint[i-1][j] + workout[i][j];
			else boyToMeetingPoint[i][j] = max(boyToMeetingPoint[i][j-1] + workout[i][j], boyToMeetingPoint[i-1][j] + workout[i][j]);
		}
	}

	rfor(i,n-1,0) {
		rep(j,m) {
			if(i == n-1 and j == 0) girlToMeetingPoint[i][j] = workout[i][j];
			else if(i == n-1) girlToMeetingPoint[i][j] = girlToMeetingPoint[i][j-1] + workout[i][j];
			else if(j == 0) girlToMeetingPoint[i][j] = girlToMeetingPoint[i+1][j] + workout[i][j];
			else girlToMeetingPoint[i][j] = max(girlToMeetingPoint[i][j-1] + workout[i][j], girlToMeetingPoint[i+1][j] + workout[i][j]);
		}
	}


	rfor(i,n-1,0) {
		rfor(j,m-1,0) {
			if(i == n-1 and j == m-1) boyToEndPoint[i][j] = workout[i][j];
			else if(i == n-1) boyToEndPoint[i][j] = boyToEndPoint[i][j+1] + workout[i][j];
			else if(j == m-1) boyToEndPoint[i][j] = boyToEndPoint[i+1][j] + workout[i][j];
			else boyToEndPoint[i][j] = max(boyToEndPoint[i][j+1] + workout[i][j], boyToEndPoint[i+1][j] + workout[i][j]);
		}
	}

	rep(i,n) {
		rfor(j,m-1,0) {
			if(i == 0 and j == m-1) girlToEndPoint[i][j] = workout[i][j];
			else if(i == 0) girlToEndPoint[i][j] = girlToEndPoint[i][j+1] + workout[i][j];
			else if(j == m-1) girlToEndPoint[i][j] = girlToEndPoint[i-1][j] + workout[i][j];
			else girlToEndPoint[i][j] = max(girlToEndPoint[i][j+1] + workout[i][j], girlToEndPoint[i-1][j] + workout[i][j]);
		}
	}

	ll ans = INT_MIN;

	repb(i,1,n-1) {
		repb(j,1,m-1) {
			ll op1 = boyToMeetingPoint[i-1][j] + girlToMeetingPoint[i][j-1] + boyToEndPoint[i+1][j] + girlToEndPoint[i][j+1];
			ll op2 = boyToMeetingPoint[i][j-1] + girlToMeetingPoint[i+1][j] + boyToEndPoint[i][j+1] + girlToEndPoint[i-1][j];
			ans = max(ans, max(op1,op2));
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

    //w(tc)
    	solve();
	
	return 0;
}