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

	ll n, k; cin >> n >> k;
    bool flip = true;

    if(k == 1) {
        string ans = string(n,'a');
        p1(ans);
        return;
    }

	queue<char> q;
	rep(i,k) q.push((char)('a'+i));

	vector<queue<char>> v(k,q);
	string ans = "a";
	char curr = 'a';
    int khatam = 0;

	repb(i,1,n) {
		if(v[ord(curr)].size() == 0) {
			v[ord(curr)] = q;
			curr = (char)('a'+(ord(curr) + 1)%k);
            khatam++;
			i--;
		} else {
			char next, first = '#';
            int ok = 0;
            while(v[ord(curr)].size() > 0) {
                next = v[ord(curr)].front();
                if(next != curr) v[ord(curr)].pop();
                if(first == '#') first = next;
                if(v[ord(next)].size() > 0){
                    ok = 1;
                    if(next == curr) v[ord(curr)].pop();
                    break;
                } 
                if(next == curr) v[ord(curr)].pop();

            }

            if(!ok) {
                // khatam++;
                // i--;
                // continue;
                next = first;
            }

			ans += next;
			curr = next;
		}

        // if(khatam == k) {
        //     khatam = 0;
        //     v = vector<queue<char>> (k,q);
        //     curr = (char)('a'+k-1);
        // }
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