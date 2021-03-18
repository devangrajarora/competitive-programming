#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c){
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool putInAlice(string str)
{
	if(str.size() == 1)
		return isVowel(str[0]);

	for(int i = 0 ; i < str.size() - 1 ; i++)
	{
		char c = str[i];
		if(isVowel(c))
			continue;
		else
		{
			if(!isVowel(str[i + 1]))
				return false;
			if(i + 2 < str.size())
				if(!isVowel(str[i + 2]))
					return false;
		}
	}

	return true;
}

double getAns(vector<string> v)
{
	cout << setprecision(7);
	int k = v.size();
	vector<char> contains;
	map<char, double> freq;

	for(int i = 0 ; i < k ; i++)
	{
		for(int j = 0 ; j < v[i].size() ; j++)
		{
			char c = v[i][j];
			if(freq[c] == 0)
				contains.push_back(c); // contains unique elements
			freq[c]++;
		}
	}

	int n[26];
	for(int i = 0 ; i < 26 ; i++)
		n[i] = 0;

	for(int i = 0 ; i < contains.size() ; i++)
	{
		char c = contains[i];
		int count = 0;

		for(int j = 0; j < k ; j++)
			if(v[j].find(c) != string::npos)
				count++;

		n[c - 'a'] = count;
	}

	double ans = 1.0;
	for(int i = 0 ; i < contains.size() ; i++)
	{
		char c = contains[i];
		double num = n[c - 'a'];
		double denom = pow(freq[c], k) * 1.0;
		ans *= ((num *1.0) / denom);
	}

	return ans;
	
}

int main()
{
	cout << setprecision(7);

	int t;
	cin >> t;

	for(int p = 0 ; p < t ; p++)
	{
		vector<string> alice, bob;
		int L;
		cin >> L;

		for(int i = 0 ; i < L ; i++)
		{
			string str;
			cin >> str;

			if(putInAlice(str))
				alice.push_back(str);
			else
				bob.push_back(str);
		}

		if(alice.size() == 0)
		{
			cout << fixed << setprecision(7) << 0 << endl;
			return 0;
		}
		else if(bob.size() == 0)
		{
			cout << "Infinity" << endl;
			return 0;
		}
		double scA = getAns(alice);
		double scB = getAns(bob);

		double ans = (scA * 1.0)/ scB;

		if(ans > 10000000.0)
			cout << "Infinity" << endl;
		else
			cout << fixed << setprecision(7) << ans << endl;
	}
}