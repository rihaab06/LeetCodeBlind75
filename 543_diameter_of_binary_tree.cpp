#include<iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
    int result= 0;
       int dfs(TreeNode* curr){
        if (!curr) return 0;
        int left = dfs(curr->left);
        int right = dfs(curr->right);
        result =  max(result,left+right);

        return 1+max(left,right);
 
        
       }
    int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return result;
    }

};

// Optional: preorder print to visualize the tree
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Preorder of tree: ";
    printPreorder(root);
    cout << endl;

    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);
    cout << "Diameter of tree: " << diameter << endl; // Output: 3

    return 0;
}