#include <iostream>
#include <vector> 
#include <string>

using namespace std;


int main()
{
    int n, elem;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {   
        string input;
        cin >> input;
        for (int j = 0; j < n; j++) {
            mat[i][j] = input[j] - '0';
        }
    }
    // 构建前序矩阵
    vector<vector<int>> prefix(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 上+左-左上-当前值
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1]
            - prefix[i-1][j-1] + mat[i-1][j-1];
        }
    }
    for (int k = 1; k <= n; k++)
    {
        if (k % 2 != 0) 
        {
            cout << 0 << endl;
            continue;
        }
        int count = 0;
        int target = (k*k) / 2;
        for (int i = 0; i <= n-k; i++)
        {
            for (int j = 0; j <= n-k; j++)
            {
                int sum = prefix[i+k][j+k] 
                - prefix[i][j+k]
                -prefix[i+k][j]
                +prefix[i][j];
                if (sum == target)
                {
                    count ++;
                }
            }
        }
        cout << count << endl;
    }
   return 0;
}