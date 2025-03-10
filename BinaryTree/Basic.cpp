#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode * leftNode;
    TreeNode * rightNode;
    TreeNode(int x) : val(x), leftNode(nullptr), rightNode(nullptr) {};
};
