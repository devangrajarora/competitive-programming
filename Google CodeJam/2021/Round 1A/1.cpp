#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
#define popb pop_back()
#define endl "\n"
#define vi vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair < long long, long long >
typedef priority_queue<ll, vector<ll>, greater<ll>> minheap;
typedef priority_queue<ll> maxheap;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
#define sortv(v) sort(v.begin(),v.end())
#define rsortv(v) sort(v.begin(),v.end(), greater<>());
#define watch(x) cout << (#x) << " is " << (x) << endl
#define w(x)  ll x; cin>>x; while(x--)

ll modPower(ll num,ll r) {
    if(r==0) return 1;
    if(r==1) return num;
    ll ans=modPower(num,r/2);
    if(r%2==0) {
        return (ans*ans);
    } return ((ans*ans))*num;
}

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

    template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
{
	bool first = true;
	os << "[";
	for (typename std::map<T1, T2>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
	{
		if(!first)
			os << ", ";
		os << *iii ;
		first = false;
	}
	return os << "]";
}

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code

int firstBigger(string a, string b) {
	ll n = a.size(), m = b.size();
	if(n > m) return 1;
	else if(n < m) return -1;
	else {
		rep(i,n) {
			if(a[i] > b[i]) return 1;
			else if(a[i] < b[i]) return -1;
		}
	}

	return 0;
}

void cases(int tc) {
	cout << "Case #" << tc << ": ";
}

void solve(int tc) {

	ll N, num; cin >> N;
	vector<string> a(N);
	ll ans = 0;
	rep(i,N) {
		cin >> num;
		a[i] = to_string(num);
	}
	
	repb(i,1,N) {

		int comp = firstBigger(a[i-1], a[i]);

		if(comp == -1) continue;
		else if(comp == 0) {
			ans++;
			a[i] += "0";

		} else {

			string one = a[i-1], two = a[i];
			ll n = one.size(), m = two.size(), i1 = 0, j1 = 0, ok = 0;
			ll diff = n-m;

			while(i1 < n and j1 < m) {
				if(one[i1] > two[j1]) {
					ans += (diff+1);
					two += string(diff+1,'0');
					ok = 1;
					break;
				} else if(one[i1] < two[j1]) {
					ans += diff;
					two += string(diff,'0');
					ok = 1;
					break;
				} else {
					i1++; j1++;
				}
			}

			if(ok) {
				a[i] = two;
				continue;
			}
			if(j1 == m) {

				ll i2 = n-1, notNine = -1;
				while(i2 >= m and one[i2] == '9') i2--;

				if(i2 == m-1) {
					ans += (diff+1);
					two += string(diff+1,'0');
				} else {
					for(ll idx = m ; idx < n ; idx++) {
						ans++;
						if(idx < i2) {
							two += to_string(one[idx]-'0');
						} else if(idx == i2) {
							two += to_string((one[idx]-'0') + 1);
						} else {
							two += "0";
						}
					}
				}
			}

			a[i] = two;
		}
	}

	cases(tc);
	// p1(a);
	p1(ans);
}

int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
	freopen("/home/devang/input.txt","r",stdin);
	freopen("/home/devang/output.txt","w",stdout);
    #endif

	int tc,x = 1;
	cin >> tc;

	while(tc--)	{
		solve(x++);
	}

	return 0;
}