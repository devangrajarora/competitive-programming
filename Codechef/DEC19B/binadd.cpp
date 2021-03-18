#include<bits/stdc++.h>
using namespace std;

	std::bitset<10000> to_bitset(std::string s)
	{
		auto binary = [](char c) { return c == '0' || c == '1'; };
		auto not_binary = [binary](char c) { return !binary(c); };

		s.erase(std::remove_if(begin(s), end(s), not_binary), end(s));

		return std::bitset<10000>(s);
	}

// 	std::string to_string(std::bitset<32> bs)
// 	{
// 		return bs.to_string();
// 	}

	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int t;
		cin >> t;

		for(int q = 0 ; q < t ; q++)
		{
			string str;
			cin >> str;
			bitset<10000> a, b;
			a = to_bitset(str);
			cin >> str;
			b = to_bitset(str);


			int ans = 0;
			bitset<10000> zero;
			while((b | zero).to_ulong() > 0)
			{
				ans++;
				bitset<10000> v = a & b;
				a = a ^ b;
				
				b = v << 1;
			}

			cout << ans << endl;

			
		}

		return 0;
	}	