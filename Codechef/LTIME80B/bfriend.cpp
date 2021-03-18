#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll getClosest(ll val1, ll val2, 
               ll target) 
{ 
    if (target - val1 >= val2 - target) 
        return val2; 
    else
        return val1; 
} 

ll findClosest(ll arr[], ll n, ll target) 
{ 
    // Corner cases 
    if (target <= arr[0]) 
        return arr[0]; 
    if (target >= arr[n - 1]) 
        return arr[n - 1]; 
  
    // Doing binary search 
    ll i = 0, j = n, mid = 0; 
    while (i < j) { 
        mid = (i + j) / 2; 
  
        if (arr[mid] == target) 
            return arr[mid]; 

        if (target < arr[mid]) { 
  

            if (mid > 0 && target > arr[mid - 1]) 
                return getClosest(arr[mid - 1], 
                                  arr[mid], target); 
  
            /* Repeat for left half */
            j = mid; 
        } 
  
        // If target is greater than mid 
        else { 
            if (mid < n - 1 && target < arr[mid + 1]) 
                return getClosest(arr[mid], 
                                  arr[mid + 1], target); 
            // update i 
            i = mid + 1;  
        } 
    } 
  
    // Only single element left after search 
    return arr[mid]; 
} 
  

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;

	for(ll q = 0 ; q < t ; q++)
	{
		ll n, a, b, c;
		cin >> n >> a >> b >> c;

		ll *f = new ll[n];
		for(ll i = 0 ; i < n ; i++)
		{
			ll elem;
			cin >> elem;
			f[i] = elem;
		}

		sort(f, f + n);

		ll avg = (a + b) / 2;

		// ll fClosestToB = findClosest(f, n, b);
		// ll fClosestToA = findClosest(f, n, a);

		// ll ans1 = (abs(fClosestToB - b)) + c + (abs(fClosestToB - a));
		// ll ans2 = (abs(fClosestToA - b)) + c + (abs(fClosestToA - a));

		ll fClosestToAvg = findClosest(f, n, avg);
		ll ans = (abs(fClosestToAvg - b)) + c + (abs(fClosestToAvg - a));
		
		// ll ans = min(ans1, ans2);

		cout << ans << endl;

		delete []f;

	}

	return 0;
}