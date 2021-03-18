#include<bits/stdc++.h>
using namespace std;

int getDistance(vector<int> v, int elem)
{
	int distance = 1;
	int i = v.size() - 2;
	while(true)
	{
		if(v[i] == elem)
			break;
		distance++;
		i--;
		if(i == 0)
			cout << "check";
	}

	return distance;
}

int main()
{
	int t;
	cin >> t;

	for(int p = 0 ; p < t ; p++)
	{
		int n;
		cin >> n;
		vector<int> v;
		int freq[130];

		for(int i = 0 ; i < 130 ; i++)
			freq[i] = 0;

		v.push_back(0);
		freq[0]++;
		
		for(int i = 1 ; i < n ; i++)
		{
			int lastElem = v.back();

			if(freq[lastElem] > 1)
			{
				int elem = getDistance(v, lastElem);
				freq[elem]++;
				v.push_back(elem);
			}
			else
			{
				v.push_back(0);
				freq[0]++;
			}
		}

		cout << freq[v.back()] << endl;
		
	}
}