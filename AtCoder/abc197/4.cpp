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
#define PI 3.14159265

void solve() {

	ll n; cin >> n;
	ld x0, y0, xOpp, yOpp; cin >> x0 >> y0 >> xOpp >> yOpp;
	ll um = (xOpp-x0) * (xOpp-x0) + (yOpp-y0) * (yOpp-y0); 
	ld oppDist = sqrt(um);
	ll sumOfAngles = (n-2) * 180;
	ld angle = sumOfAngles*1.0 / n;
	// p2(oppDist,angle);
	ld halfAngle = angle/2, halfDist = oppDist/2;
	ld side = 2*halfDist*cos(halfAngle*PI/180.0);

	// ld y = side * sin(halfAngle*PI/180.0);
	// ld x = side * cos(halfAngle*PI/180.0);

	ld AB = halfDist, AC = side, BC = halfDist;
	ld cy = ((AB*AB) + (AC*AC) - (BC*BC)) / (2 * AB);
	ld cx = sqrt(AC*AC - cy*cy);
	ld cx
	p2(cx, cy);
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