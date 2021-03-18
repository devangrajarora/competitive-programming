#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for(int p = 0 ; p < t ; p++)
	{
		int n;
		cin >> n;
		map<int, int> m; // first -> index, second -> freq

		for(int i = 0 ; i < n ; i++)
		{
			string str;
			cin >> str;

			for(int j = 0 ; j < 10 ; j++)
				if(str[j] == '1')
					m[j]++;
		}

		int count = 0;
		for(int i = 0 ; i < 10 ; i++)
			if(m[i] % 2 == 1)
				count++;

		cout << count << endl;
	}
}