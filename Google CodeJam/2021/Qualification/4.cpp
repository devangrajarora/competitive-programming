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

void cases(int tc) {
	cout << "Case #" << tc << ": ";
}

int n, q;
vi hidden(51), temp(51), indexes(51);

void genRandomArray() {
	rep(i,n) hidden[i] = (rand()%100)+1; p0("hidden:"); 
	rep(i,n) p0(hidden[i]); p1("");	
}

int query(int i, int j, int k) {
	cout << i+1 << " " << j+1 << " " << k+1 << "\n";
	if(hidden[i] >= min(hidden[j], hidden[k]) and hidden[i] <= max(hidden[j], hidden[k])) return i+1;
	if(hidden[j] >= min(hidden[i], hidden[k]) and hidden[j] <= max(hidden[i], hidden[k])) return j+1;
	if(hidden[k] >= min(hidden[i], hidden[j]) and hidden[k] <= max(hidden[i], hidden[j])) return k+1;
}

void assignIndexes(int &smallIdx, int &midIdx, int &bigIdx, int q1, int q2, int q3, int median, int &i, int &j) {
	midIdx = median-1;
	if(q1 == median) smallIdx = q3-1, bigIdx = -1, i++, j++;
	else if(q2 == median) smallIdx = q1-1, bigIdx = q3-1, i+= 2, j++;
	else if(q3 == median) smallIdx = q1-1, bigIdx = q2-1, i += 2, j++;

}

void merge(int l, int mid, int h) {
	int idx = l, i = l, j = mid+1, q1, q2, q3, smallIdx, midIdx, bigIdx, median;
	while(i <= mid and j <= h) {
		if(i < mid) {
			q1 = indexes[i], q2 = indexes[i+1], q3 = indexes[j];
			median = query(q1,q2,q3);
		} else if(j < h) {
			q1 = indexes[i], q2 = indexes[j], q3 = indexes[j+1];
			median = query(q1,q2,q3);
		} else { // two elements left
			if(i == 0 and j < h) {
				q1 = indexes[i], q2 = indexes[j], q3 = indexes[j+1];
				median = query(q1,q2,q3);
			} else if(i > 0) {
				q1 = indexes[i-1], q2 = indexes[i], q3 = indexes[j];
				median = query(q1,q2,q3);
			} else {
				p1("F"); return;
			}
		}

		assignIndexes(smallIdx, midIdx, bigIdx, q1, q2, q3, median, i, j);
		temp[idx++] = smallIdx; 
		temp[idx++] = midIdx;
		if(bigIdx != -1) temp[idx++] = bigIdx;  
	}

	while(i <= mid) temp[idx++] = indexes[i++];
	while(j <= h) temp[idx++] = indexes[j++];
	repeb(i,l,h) indexes[i] = temp[i];

}

void mergesort(int l, int h) {

	if(l >= h) return; 
	int mid = (l + h) / 2; 
	mergesort(l,mid);
	mergesort(mid+1,h);
	merge(l,mid,h);
}

void solve() {

	rep(i,n) indexes[i] = i;
	mergesort(0,n-1);
	p1(indexes);
}

int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif

	int tc,x = 1;
	cin >> tc >> n >> q;

	while(tc--)	{
		genRandomArray();
		solve();
	}

	return 0;
}