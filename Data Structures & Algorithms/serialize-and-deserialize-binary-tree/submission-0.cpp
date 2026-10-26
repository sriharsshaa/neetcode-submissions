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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==nullptr){
                ans+="N,";
                continue;
            }
            ans+=to_string(curr->val)+",";
            q.push(curr->left);
            q.push(curr->right);
        } 
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream ss(data);
        string val;
        getline(ss,val,',');
        queue<TreeNode*> q;
        TreeNode* root=new TreeNode(stoi(val));
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(!getline(ss,val,',')) break;
            if(val!="N"){
                curr->left=new TreeNode(stoi(val));
                q.push(curr->left);
            }
            if(!getline(ss,val,',')) break;
            if(val!="N"){
                curr->right=new TreeNode(stoi(val));
                q.push(curr->right);
            }
        }
        return root;
    }
};
