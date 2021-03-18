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
		int n;
		cin >> n;
		string str;
		cin >> str;

		int visited[26]{0};
		int lastOccurance[26];
		int minDistance = INT_MAX, flag = 0;
		for(int i = 0 ; i < str.length() ; i++)
		{
			char c = str[i];
			int index = c - 'a';

			if(visited[index] == 0) {
				visited[index] = 1;
				lastOccurance[index] = i;
			} else {
				flag = 1;
				int dist = i - lastOccurance[index];
				lastOccurance[index] = i;
				if(dist < minDistance)
					minDistance = dist;
			}

		}

		if(flag == 0)
			cout << 0 << "\n";
		else
			cout << str.length() - minDistance << "\n"; 
	}

	return 0;
}