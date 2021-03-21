#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main()
{
	ll n, a, b, k, points = 0;
	cin >> n >> a >> b >> k;
	vector<int> remaining;

	for(int i = 0 ; i < n ; i++)
	{
		ll h;
		cin >> h;
		ll sum = a + b;

		h = h % sum;

		// dying hit
		if(h == 0) {
			remaining.push_back(b);
		} else if(h <= a) {
			points++;			
		} else if(h > a){
			remaining.push_back(h - a);
		} 
	}

	sort(remaining.begin(), remaining.end());

	for(int i = 0 ; i < remaining.size() ; i++)
	{
		if(k <= 0)
			break;
		ll rem = remaining[i];

		if(rem <= a) {
			k--;
			points++;
			if(k <= 0)
				break;
		} else {
			ll fac = rem / a;
			if(rem % a != 0)
				fac++;

			if(k >= fac) {
				k = k - fac;
				points++;
				if(k <= 0)
					break;
			} else {
				break;
			}
		}

		if(k <= 0)
			break;
	}

	cout << points;

}