#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

	template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
        {
            if(!first)
                os << ", ";
            os << *iii;
            first = false;
        }
        return os << "]";
    }
    
/*-------------------------------------------------*/

// read once, read again, think, code
#define MAXM 1e5

struct primeFactorization {
    ll countOfPf, primeFactor;
};
  
vi divisors; 

void generateDivisors(ll curIndex, ll curDivisor, vector<primeFactorization>& arr)
{
  
    if (curIndex == arr.size()) {
        divisors.pb(curDivisor);
        return;
    }
  
    for (ll i = 0; i <= arr[curIndex].countOfPf; ++i) {
    	if(curDivisor > MAXM) break;
        generateDivisors(curIndex + 1, curDivisor, arr);
        curDivisor *= arr[curIndex].primeFactor;
    }
}

void findDivisors(ll n)
{
 
    vector<primeFactorization> arr;
    divisors.clear();
  
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ll count = 0;
            while (n % i == 0) {
                n /= i;
                count += 1;
            }

            arr.push_back({ count, i });
        }
    }
  
    if (n > 1) {
        arr.push_back({ 1, n });
    }
  
    ll curIndex = 0, curDivisor = 1;
    for(auto &it : arr) {
    	it.countOfPf *= 2;
    }

    generateDivisors(curIndex, curDivisor, arr);
}
  

void solve() {

    ll n, m, ans = 0, z = 0;
    cin >> n >> m;
    unordered_set<ll> nx, ny, px, py;

    rep(i,n) {
    	ll num;
    	cin >> num;
    	if(num < 0) {
    		num = abs(num);
    		nx.insert(num);
    	} else if(num > 0) {
    		px.insert(num);
    	} else {
    		z++;
    	}
    }

	rep(i,m) {
    	ll num;
    	cin >> num;
    	if(num < 0) {
    		num = abs(num);
    		ny.insert(num);
    	} else if(num > 0) {
    		py.insert(num);
    	} else {
    		z++;
    	}
    }

    // p1(px);
    // p1(nx);
    // p1(py);
    // p1(ny);

    ans = (px.size() + nx.size()) * (py.size() + ny.size()) * z;

    for(auto &X1 : nx) {
    	findDivisors(X1);
    	ll sq = X1*X1;
    	for(auto &divisor : divisors) {
    		if(py.find(divisor) != py.end() and ny.find(sq/divisor) != ny.end()) ans++;
    	}
    }

	for(auto &X1 : px) {
    	findDivisors(X1);
    	ll sq = X1*X1;
    	for(auto &divisor : divisors) {
    		if(py.find(divisor) != py.end() and ny.find(sq/divisor) != ny.end()) ans++;
    	}
    }

	for(auto &Y1 : ny) {
    	findDivisors(Y1);
    	ll sq = Y1*Y1;
    	for(auto &divisor : divisors) {
    		if(px.find(divisor) != px.end() and nx.find(sq/divisor) != nx.end()) ans++;
    	}
    }

	for(auto &Y1 : py) {
		findDivisors(Y1);
    	ll sq = Y1*Y1;
    	for(auto &divisor : divisors) {
    		if(px.find(divisor) != px.end() and nx.find(sq/divisor) != nx.end()) ans++;
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