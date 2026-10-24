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
int pre=0;
TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l,int r){
    if(l>r) return nullptr;
    int rootval=preorder[pre++];
    TreeNode* root=new TreeNode(rootval);
    int i=l;
    while(inorder[i]!=rootval){
        i++;
    }
    root->left=build(preorder,inorder,l,i-1);
    root->right=build(preorder,inorder,i+1,r);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,inorder.size()-1);
    }
};
