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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q) return root;
        TreeNode* lh=lowestCommonAncestor(root->left,p,q);
        TreeNode* rh=lowestCommonAncestor(root->right,p,q);
        if(lh!=nullptr && rh!=nullptr) return root;
        if(lh!=nullptr) return lh;
        return rh;
    }
};
