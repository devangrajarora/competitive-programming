#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define p1(a) cout << a << "\n"


int main()
{

    ll tc; cin >> tc;
    while(tc--) {
    	ll num; cin >> num;
	ll numA = 0, numB = 0;
    vector<int> a(32,0), b(32,0), a1(32,0), b1(32,0);
    int oneOccured = 0;
    for(int i = 31 ; i >= 0 ; i--) {
		b[31-i] = oneOccured;
		if(1<<i & num) {
			if(!oneOccured) {
				oneOccured = 1;
				a[31-i] = 1;
			}

			if(oneOccured) a1[31-i] = b1[31-i] = 1;

		} else {
			a[31-i] = b[31-i];
		}


		numA += a[31-i]*1<<i;
		numB += b[31-i]*1<<i;
    }

    p1(numA*numB);
    }
	
	return 0;
}