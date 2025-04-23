#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N, 0);
    vector<int> preSum(N, 0);
    int accumSum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        accumSum += arr[i];
        preSum[i] = accumSum;
    }
    int a, b;
    while(cin >> a >> b)
    {
        int result = 0;
        if (a == 0) result = preSum[b];
        else result = preSum[b] - preSum[a-1];
        cout << result << endl; 
    }
    return 0;
}