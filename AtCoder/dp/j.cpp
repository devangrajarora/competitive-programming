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

const int MAXM = 302;
#define vd vector<double>
#define vvd vector<vd>
#define vvvd vector<vvd>

// E(v) = P(X) * X


void solve() {

    int n, sushis; cin >> n;
    int one = 0, two = 0, three = 0;
    rep(i,n) {
    	cin >> sushis;
    	if(sushis == 1) one++;
    	if(sushis == 2) two++;
    	if(sushis == 3) three++;
    }

    vvvd prob(MAXM, vvd(MAXM, vd(MAXM, 0.0)));
    vvvd ev(MAXM, vvd(MAXM, vd(MAXM, 0.0)));

	// ev(a,b,c) = expected no of turns to reach state (a,b,c)
	// prob(a,b,c) = probabiltiy of reaching (a,b,c)

    prob[one][two][three] = 1;

    for(int c = three ; c >= 0 ; c--) {
    	for(int b = three + two ; b >= 0 ; b--) { // we can have max three + two plates with two sushis
    		for(int a = one + two + three ; a >= 0 ; a--) { // we can have max three + two + one plates with one sushis
    			if(a == 0 and b == 0 and c == 0) continue;
    			if(a + b + c > n) continue;

    			double probOfGettingEmptyPlate = (double) (n - (a+b+c)) / n;
    			// transition happens after getting empty plate x(0 to inf) no of times and then one valid plate
    			// (probOfGettingEmptyPlate) + (probOfGettingEmptyPlate)^2 + (probOfGettingEmptyPlate)^3 ... + 1
    			double noOfTurnsHere = probOfGettingEmptyPlate / (1.0 - probOfGettingEmptyPlate) + 1; 
    			
    			// EV(X) = prob(X) * X
    			ev[a][b][c] += prob[a][b][c] * noOfTurnsHere;

    			// remove 1
    			if(a > 0) {
	    			double probOfTransition = (a*1.0) / (a+b+c);
	    			prob[a-1][b][c] +=  prob[a][b][c] * probOfTransition;
	    			ev[a-1][b][c] += ev[a][b][c] * probOfTransition;
	    		}

	    		// remove 2
	    		if(b > 0) {
	    			double probOfTransition = (b*1.0) / (a+b+c);
	    			prob[a+1][b-1][c] += prob[a][b][c] * probOfTransition;
	    			ev[a+1][b-1][c] += ev[a][b][c] * probOfTransition;
	    		}

	    		// remove 3
	    		if(c > 0) {
	    			double probOfTransition = (c*1.0) / (a+b+c);
	    			prob[a][b+1][c-1] += prob[a][b][c] * probOfTransition;
	    			ev[a][b+1][c-1] += ev[a][b][c] * probOfTransition;
	    		}
    		}
    	}
    }

    // expected value on reaching (0,0,0)
    cout << fixed << setprecision(10) << ev[0][0][0];
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