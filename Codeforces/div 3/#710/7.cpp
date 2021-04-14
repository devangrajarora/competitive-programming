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
	return (int)(c-'a');
}

void solve() {

	string s; cin >> s;
	ll n = s.size();
	vector<bool> exists(26, false);

    rep(i,n) exists[ord(s[i])] = true;
    int st = 0;

    while(true) {
		
		bool ok = false;
		for(char putHere = 'z' ; putHere >= 'a' ; putHere--) {
			if(exists[ord(putHere)]) {
				int pos = st;
				while(pos < n and s[pos] != putHere) pos++;

				vector<bool> existsInSuffix(26, false);
				repb(i,pos,n) {
					if(exists[ord(s[i])]) {
						existsInSuffix[ord(s[i])] = true;
					}
				}

				if(exists == existsInSuffix) { // can use putHere
					cout << putHere;
					exists[ord(putHere)] = false;
					st = pos + 1;
					ok = true;
					break;
				}
			}
		}
		if(!ok) break;
    }

    p1("");
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