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

int ord(char c) {
    return c-'0';
}

void solve() {

    ll n;
    string s1, s2, s3;
    cin >> n;
    cin >> s1 >> s2 >> s3;

    string ans = "";

    ll p1 = 0, p2 = 0, p3 = 0;

    while(max({p1,p2,p3}) < 2*n) {

        int cnt = ord(s1[p1]) + ord(s2[p2]) + ord(s3[p3]);
        int opt = (cnt >= 2) ? 1 : 0;
        ans += to_string(opt);
        if(ord(s1[p1]) == opt) p1++;
        if(ord(s2[p2]) == opt) p2++;
        if(ord(s3[p3]) == opt) p3++;
    }

    if(p1 == 2*n) {
        if(p2 > p3) while(p2 < 2*n) ans += s2[p2++];
        else while(p3 < 2*n) ans += s3[p3++];
    } else if(p2 == 2*n) {
        if(p1 > p3) while(p1 < 2*n) ans += s1[p1++];
        else while(p3 < 2*n) ans += s3[p3++];
    } else if(p3 == 2*n) {
        if(p1 > p2) while(p1 < 2*n) ans += s1[p1++];
        else while(p2 < 2*n) ans += s2[p2++];
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

    w(tc) {
    	solve();
    }
	
	return 0;
}