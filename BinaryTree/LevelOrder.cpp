#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

vector<vector<int>> levelOrder(TreeNode * root)
{
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        vector<int> tmpResult;
        
        for (int i = 0; i < size; i++)
        {
            TreeNode * cur = que.front(); 
            que.pop();
            tmpResult.push_back(cur->val);
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        result.push_back(tmpResult);
    }
    return result;
}