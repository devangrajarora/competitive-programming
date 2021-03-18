#include<bits/stdc++.h>
#define ll long long int 
#define MOD 1000000007
using namespace std;


int findMinVertex(int *distance, bool *visited, int n)
{
    int min = INT_MAX, minIndex = 0;
    for(int i = 0 ; i < n ; i++)
        if(!visited[i] && distance[i] < min)
        {
            min = distance[i];
            minIndex = i;
        }

    return minIndex;
}

void dijkstra(int **adj, int *distance, bool *visited, int n)
{
    for(int j = 0 ; j < n ; j++)
    {
        int curr = findMinVertex(distance, visited, n);
        visited[curr] = true;

        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i] && adj[curr][i] != 0)
            {
                int currDistance = distance[curr] + adj[curr][i];
                if(currDistance < distance[i])
                    distance[i] = currDistance;
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	for(int q = 0 ; q < t ; q++)
	{
		int n, k;
		cin >> n >> k;

		int **adj = new int*[n];
		for(int i = 0 ; i < n ; i++)
			adj[i] = new int[n];

		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				adj[i][j] = 0;

	//	int V = 0;
		for(int i = 0 ; i < n ; i++)
		{
			string str;
			cin >> str;

			for(int j = i - k ; j <= i + k ; j++)
			{
				if(j == i)
					continue;

				if(j >= 0 && j < n)
					if(str[j] == '1')
					{
						adj[i][j] = 1;
					//	V++;
					}
			}
		}

	bool *visited = new bool[n];
    for(int i = 0 ; i < n ; i++)
        visited[i] = false;

    int *distance = new int[n];
    for(int i = 1 ; i < n ; i++)
        distance[i] = INT_MAX;

     distance[0] = 0;

    dijkstra(adj, distance, visited, n);   

    int ans = distance[n - 1];
    
    if(ans > 1000000)
    	cout << -1 << endl;
    else
    	cout << ans << endl;

    	delete []distance;
    	delete []visited;

        for(int i = 0 ; i < n ; i++)
            delete[] adj[i];
        delete[] adj;

	}

	return 0;
}