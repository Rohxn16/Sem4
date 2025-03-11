#include <bits/stdc++.h>

using namespace std;

int MaxSubarraySum(vector<int>arr, int low, int high)
{
    
}

int MaxSubarraySumBrute(vector<int>arr, int low, int high)
{
    
}

int main(int argc, const char *argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    int res = MaxSubarraySumBrute(arr,0,arr.size());
    cout << res << endl;


}