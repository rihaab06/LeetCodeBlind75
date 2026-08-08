#include<iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution{
public:
    TreeNode*invertTree(TreeNode* root){
        if (!root)
        {
            return nullptr;
        }
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);
    return root;
    }


};

void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {

    Solution sol;
    // Build sample tree
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "Original tree (Preorder): ";
    printPreorder(root);
    cout << endl;

    sol.invertTree(root);

    cout << "Inverted tree (Preorder): ";
    printPreorder(root);
    cout << endl;

    return 0;
}

    