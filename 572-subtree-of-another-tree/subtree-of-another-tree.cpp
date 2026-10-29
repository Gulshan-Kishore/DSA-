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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) 
            return p == q;
        
        int isLeftSame = isSameTree(p->left, q->left);
        int isRightSame = isSameTree(p->right, q->right);

        return isLeftSame && isRightSame && p->val == q->val;
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL || subRoot == NULL)
            return root == subRoot;
        
        if (root->val == subRoot->val && isSameTree(root, subRoot))
            return true;
        
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};