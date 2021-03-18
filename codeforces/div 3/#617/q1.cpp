#include<bits/stdc++.h>
#define ll long long int 
#define MOD 1000000007
// #define FOR(i,n) for(int i = 0 ; i < n ; i++)
// #define FOR(i,a,b) for(int i = a ; i < b ; i++)
#define pb push_back
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCases;
	cin >> testCases;

	for(int it = 0 ; it < testCases ; it++)
	{
		int n, oddCtr = 0, evenCtr = 0;
		cin >> n;
		int a[n];
		for(int i = 0 ; i < n ; i++)
		{
			int elem;
			cin >> elem;
			if(elem % 2 == 0)
				evenCtr++;
			else
				oddCtr++;
		}

		if(oddCtr == 0 || (evenCtr == 0 && oddCtr % 2 == 0))
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
	}

	return 0;
}