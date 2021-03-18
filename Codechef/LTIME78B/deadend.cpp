#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	typedef pair<int, int> pairs;

	for(int q = 0 ; q < t ; q++)
	{
		int n, ans = 0;
		cin >> n;

		vector<pairs> v;

		for(int i = 0 ; i < n ; i++)
		{
			int pos;
			cin >> pos;
			pairs x = make_pair(pos, false);
			v.push_back(x);
		}

		sort(v.begin(), v.end());

		// for(int i = 0 ; i < v.size() ; i++)
		// 	cout << v[i].first << "  " << v[i].second << endl;

		for(int i = 0 ; i < v.size() ; i++)
		{
			if(v[i].second == true)
				continue;

			else if(i != 0 && abs(v[i].first - v[i - 1].first) == 1)
			{
				v[i].second = true;
				v[i - 1].second = true;
				
			
			}

			else if(i != v.size() - 1 && abs(v[i + 1].first - v[i].first) == 1)
			{
				v[i].second = true;
				v[i + 1].second = true;
				
				
			}

			else if(i != 0 && abs(v[i].first - v[i - 1].first) == 2 && v[i - 1].second == false)
			{
				v[i].second = true;
				v[i - 1].second = true;
				
				ans++;
				
			}

			else if(i != v.size() - 1 && abs(v[i + 1].first - v[i].first) == 2)
			{
				v[i].second = true; 
				v[i + 1].second = true;
				
				ans++;
				
			}

			
			else if(i != 0 && abs(v[i].first - v[i - 1].first) == 2)
			{
				v[i].second = true;
				v[i - 1].second = true;
				
				ans++;
				
			}

		}

		
		for(int i = 0 ; i < v.size() ; i++)
		{
			if(v[i].second == false)
				ans++;
		}		

		cout << ans << endl;
	}

	return 0;
}