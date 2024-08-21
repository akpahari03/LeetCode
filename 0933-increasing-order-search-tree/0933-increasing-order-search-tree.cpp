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
    void inorder(TreeNode* root,vector<int>& in) {
        if(root==NULL) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* convert(vector<int>& in) {
        TreeNode* root= new TreeNode(in[0]);
        TreeNode* curr=root;
        curr->left=NULL;
        for(int i=1;i<in.size();i++) {
            TreeNode* temp=new TreeNode(in[i]);
            curr->right=temp;
            curr=curr->right;
            curr->left=NULL;
        }
        return root;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        return convert(in);
    }
};