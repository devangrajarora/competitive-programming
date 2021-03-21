#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define repe(i,n) for(int i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(int i = a ; i < b ; i++)
#define repeb(i,a,b) for(int i = a ; i <= b ; i++)
#define rfor(i,n,a) for(int i = n ; i >= a ; i--)
#define pb push_back
#define popb pop_back()
#define endl "\n"
#define pii pair<int,int> 
#define pll pair < long long, long long >
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
#define sortv(v) sort(v.begin(),v.end())
#define rsortv(v) sort(v.begin(),v.end(), greater<>());
#define sortby(v,prop) sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop < rhs.prop; });
#define rsortby(v,prop) sort( v.begin( ), v.end( ), [ ]( const auto& lhs, const auto& rhs ){ return lhs.prop > rhs.prop; });


/*-------------------------------------------------*/

void buildTree(int *a, int *maxSeg, int *sumSeg, int node, int start, int end)
{
    if(start == end) {
        maxSeg[node] = a[start];
        sumSeg[node] = a[start];
    }
    else {
        int mid = (start + end) / 2;
        buildTree(a,maxSeg,sumSeg,2*node+1, start, mid);
        buildTree(a,maxSeg,sumSeg,2*node+2, mid+1, end);
        maxSeg[node] = max(maxSeg[2*node+1],maxSeg[2*node+2]);
        sumSeg[node] = sumSeg[2*node+2] + sumSeg[2*node+1];
    }
}

pii query(int *a, int *maxSeg, int *sumSeg, int node, int start, int end, int l, int r)
{
    if(r < start or end < l) {
        return {0,INT_MIN};
    }
    if(l <= start and end <= r){
        return {sumSeg[node],maxSeg[node]};
    }
    int mid = (start + end) / 2;
    pii p1 = query(a,maxSeg,sumSeg,2*node+1, start, mid, l, r);
    pii p2 = query(a,maxSeg,sumSeg,2*node+2, mid+1, end, l, r);
    return {p1.fi + p2.fi, max(p1.se,p2.se)};
}

int main()
{
	fastio;
	
		int n,ans = INT_MIN;
		cin >> n;

		int a[n], maxSeg[4*n], sumSeg[4*n];

		memset(maxSeg,INT_MIN,sizeof(maxSeg));
		memset(sumSeg,INT_MIN,sizeof(sumSeg));

		rep(i,n) {
			cin >> a[i];
		}

		buildTree(a,maxSeg,sumSeg,0,0,n-1);

		rep(s,n) {
			repb(e,s,n) {
				pii p = query(a,maxSeg,sumSeg,0,0,n-1,s,e);
				ans = max(ans,(p.fi-p.se));
			}
		}

		p1(ans);
	

	return 0;
}