#include<bits/stdc++.h>
using namespace std;

class obj
{
public:
	int colour;
	int data;

	obj(int c, int d) {
		colour = c;
		data = d;
	}

	bool operator < (const obj& str) const
    {
        return (data < str.data);
    }
};


int main()
{
	int t;
	cin >> t;

	for(int p = 0 ; p < t ; p++)
	{
		int n, m;
		cin >> n >> m;

		// creating vector of objs
		vector<obj> v;
		for(int i = 0 ; i < n ; i++)
		{
			int elem;
			cin >> elem;
			obj temp(i % m, elem);
			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		int min = 9999999999;

		for(int i = 0 ; i <= n - m ; i++) // every combination
		{
			int flag = 1;
			vector<int> ans;
			for(int j = 0 ; j < m ; j++) // looking for each colour
			{
				flag = 1;
				for(int k = i ; k < n ; k++) // looking for indices of each colour close to i th element
				{
					if(v[k].colour == j) {
						ans.push_back(v[k].data);
						break;
					}

					if(k == n - 1) {
						flag = 0;
						break;
					}
				}

				if(flag == 0)
					break;
			}

			if(flag == 1)
			{
			
				int temp = (*max_element(ans.begin(), ans.end())) - (*min_element(ans.begin(), ans.end()));
				if(min > temp)
					min = temp;
			}
		}

		cout << min << endl;

		
	}
	
}