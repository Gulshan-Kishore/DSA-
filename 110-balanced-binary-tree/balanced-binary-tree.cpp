/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root, int &diff) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = height(root->left, diff);
        int rightHeight = height(root->right, diff);

        int maxHeight = max(leftHeight, rightHeight);
        diff =max(diff, abs(leftHeight - rightHeight));
        return 1 + maxHeight;
    }

    bool isBalanced(TreeNode* root) {
        int diff = 0;
        height(root, diff);

        return diff <= 1;
    }
};