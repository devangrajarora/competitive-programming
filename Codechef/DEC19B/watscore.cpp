#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	for(int q = 0 ; q < t ; q++)
	{
		int n, maxMarks[9]{0};
		cin >> n;

		for(int i = 0 ; i < n ; i++)
		{
			int index, marks;
			cin >> index >> marks;

			if(index <= 8)
				if(maxMarks[index] < marks)
						maxMarks[index] = marks;
		}

		int sum = 0;

		for(int i = 1 ; i <= 8 ; i++)
			sum += maxMarks[i];

		cout << sum << endl;
	}

	return 0;
}	