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
int dfs(TreeNode* root,int mx){
    if(root==nullptr) return 0;
    int c=0;
    if(root->val>=mx) c=1;
    mx=max(mx,root->val);
    c+=dfs(root->left,mx);
    c+=dfs(root->right,mx);
    return c; 
}
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
