#include <bits/stdc++.h>
using namespace std;

void swapMax(string &arr, int target_position, int current_position)
{
    int aux = 0;
    for (int i = current_position;
         i > target_position; i--) {
        aux = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = aux;
    }
}

string maximizeArray(string arr, int length, int swaps)
{
    if (swaps == 0)
        return arr;
 
    for (int i = 0; i < length; i++) {
        int max_index = 0, max = INT_MIN;
 
        int limit = (swaps + i) > length ? length : swaps + i;

        for (int j = i; j <= limit; j++) {
            if (arr[j] > max) {
                max = arr[j];
                max_index = j;
            }
        }
 
        swaps -= (max_index - i);

        swapMax(arr, i, max_index);
 
        if (swaps == 0)
            break;
    }

    return arr;
}

string maximize(string number, int k) {
    return maximizeArray(number, number.size(), k);
}
 
int main()
{ 
    #ifndef ONLINE_JUDGE
        freopen("/home/devang/input.txt","r",stdin);
        freopen("/home/devang/output.txt","w",stdout);
    #endif
    
    string arr; cin >> arr;
    int k; cin >> k;
    cout << maximize(arr, k);
    return 0;
}