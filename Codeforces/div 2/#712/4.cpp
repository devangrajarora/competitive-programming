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
#define vi vector<int>
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

#define FLUSH fflush(stdout); fflush(stdin)

vvi a(101,vi(101, 0));

bool black(bool rOdd, bool cOdd) {
	return (rOdd and cOdd) or (!rOdd and !cOdd);
}

ll n;

bool place1() {
	repeb(i,1,n) {
		repeb(j,1,n) {
			if(a[i][j]) continue;
			bool rOdd = i%2, cOdd = j%2;
			if(black(rOdd, cOdd)) {
				a[i][j] = 1;
				p3(1,i,j); FLUSH;
				return true;
			}
		}
	}

	return false;
}

bool place2() {
	repeb(i,1,n) {
		repeb(j,1,n) {
			if(a[i][j]) continue;
			bool rOdd = i%2, cOdd = j%2;
			if(!black(rOdd, cOdd)) {
				a[i][j] = 2;
				p3(2,i,j); FLUSH;
				return true;
			}
		}
	}

	return false;
}

void place3() {
	repeb(i,1,n) {
		repeb(j,1,n) {
			if(a[i][j]) continue;
			int up = (i == 1) ? 0 : a[i-1][j];
			int down = (i == n) ? 0 : a[i+1][j];
			int right = (j == n) ? 0 : a[i][j+1];
			int left = (j == 1) ? 0 : a[i][j-1];

			if(up != 3 and down != 3 and right != 3 and left != 3) {
				a[i][j] = 3;
				p3(3,i,j); FLUSH;
				return;
			}
		}
	}
}


void solve() {

    ll c; cin >> n;
    ll sq = n*n;
    
    repeb(cnt,1,sq) {

    	FLUSH;
    	cin >> c;

    	// 1 on black
    	// 2 on white
    	// 3 anywhere when no option

    	if(c == 1) {
    		if(place2());
    		else place3();
    	} else if(c == 2) {
    		if(place1());
    		else place3();
    	} else {
    		if(place1());
    		else place2();
    	}
    }
}


int main()
{

    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

    //w(tc)
    	solve();
	
	return 0;
}