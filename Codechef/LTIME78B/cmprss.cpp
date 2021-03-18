#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for(int q = 0 ; q < t ; q++)
	{
		int n;
		cin >> n;

		vector<int> v;
		for(int i = 0 ; i < n ; i++)
		{
			int pos;
			cin >> pos;
			v.push_back(pos);
		}

		string str = "";
		int cont = 0;

		for(int i = 0 ; i < v.size() ; i++)
		{
			int j = i;
			bool flag = false;
			while(v[j + 1] - v[j] == 1)
			{
				if(j == v.size() - 1)
					break;
				flag = true;
				cont++;
				j++;
			}

			if(flag && cont > 1)
			{
				str += to_string(v[i]);
				str += "...";
				str += to_string(v[j]);
				str += ",";
				i = j;
			}
			else
			{
				str += to_string(v[i]);
				str += ",";

			}

			flag = false;
			cont = 0;



		}

		if(!str.empty())
			str.pop_back();

		cout << str << endl;
	}

	return 0;
}