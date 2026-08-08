#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool valid(TreeNode* node, long left, long right) {
        if (!node) return true;
        if (node->val <= left || node->val >= right) {
            return false;
        }
        return valid(node->left, left, node->val) &&
               valid(node->right, node->val, right);
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
};

int main() {
    Solution sol;

    // ✅ Example 1: Valid BST
    //       2
    //      / \
    //     1   3
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    cout << "Tree 1 is BST? " << (sol.isValidBST(root1) ? "Yes" : "No") << endl;

    // ❌ Example 2: Invalid BST
    //       5
    //      / \
    //     1   4
    //        / \
    //       3   6
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    cout << "Tree 2 is BST? " << (sol.isValidBST(root2) ? "Yes" : "No") << endl;

    return 0;
}
