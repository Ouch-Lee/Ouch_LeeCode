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
    vector<vector<int>> preMat;
    
}