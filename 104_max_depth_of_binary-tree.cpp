#include<iostream>
using namespace std;
struct TreeNode
{
     int val;
      TreeNode *left;
      TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};;
   };

class Solution{
public:
     int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }

};
int main(){
       TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int depth = sol.maxDepth(root);
    cout << "Maximum Depth: " << depth << endl;  // Output: 3

    return 0;
return 0;
}