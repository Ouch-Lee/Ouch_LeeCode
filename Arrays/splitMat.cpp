#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
    int n, m, tmp, tmpRowSum, tmpColSum, matSum;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    vector<int> rowSum(n, 0);
    vector<int> colSum(m, 0);
    tmpRowSum = 0; 
    tmpColSum = 0;
    matSum = 0;
    for (int i = 0; i < n; i++)
    {
        int rowAccum = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            mat[i][j] = tmp;
            matSum += tmp;
            tmpRowSum += tmp;
            // 累计列
            rowAccum += tmp;
            // 把每一行累计到最终
            colSum[j] += rowAccum;
        }
        rowSum[i] = tmpRowSum;
    }

    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int tmpResult = abs(matSum - 2 * rowSum[i]);
        if (tmpResult < result) result = tmpResult;
    }
    for (int i = 0; i < m; i++)
    {
        int tmpResult = abs(matSum - 2 * colSum[i]);
        if (tmpResult < result) result = tmpResult;
    }
    cout << result << endl;
    return 0;
}