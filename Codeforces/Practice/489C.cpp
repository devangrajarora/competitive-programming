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

string makeBig(ll n, ll sum) {
	string ans(n,'0');
	rep(i,n) {
		if(sum > 9) {
			ans[i] = '9', sum -= 9;
		} else {
			ans[i] = ('0'+sum), sum = 0;
		}
	}	

	return ans;
} 

string makeSmall(ll n, ll sum) {
	string ans(n,'0');
	rfor(i,n-1,0) {
		if(sum > 9) {
			ans[i] = '9', sum -= 9;
		} else {
			if(i == 0) {
				ans[i] = ans[0] = ('0'+sum), sum = 0;
			} else {
				ans[i] = ('0'+sum-1), sum = 0, ans[0] = '1';
			}
			break;
		}
	}	

	return ans;
}

void solve() {

	ll n, sum; cin >> n >> sum;    
	if(sum == 0 or sum > 9*n) {
		if(sum == 0 and n == 1) p1("0 0");
		else p0("-1 -1");
	} else {
		string small = makeSmall(n,sum);
		string big = makeBig(n,sum);
		p2(small,big);
	}
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