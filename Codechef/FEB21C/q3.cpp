#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int tc;
    cin >> tc;

    while(tc--) {
    	int n, ans = 0;
	    cin >> n;

	    string s;
	    vector<string> fw(n), suffix(n);
	    map<string,int> m;


	    for(int i = 0 ; i < n ; i++) {
	    	cin >> fw[i];
	    	m[fw[i]] = 1;
	    	suffix[i] = fw[i].substr(1);
	    }

	    for(int i = 0 ; i < n ; i++) {
	    	for(int j = i+1 ; j < n ; j++) {
	    		if(fw[i][0] == fw[j][0] or suffix[i] == suffix[j]) continue;
				string nfw1 = fw[i][0] + suffix[j];
				string nfw2 = fw[j][0] + suffix[i];
				if(m[nfw1] == 0 and m[nfw2] == 0) ans += 2;
		    }
	    }

	    cout << ans << "\n";
    }
	
	return 0;
}