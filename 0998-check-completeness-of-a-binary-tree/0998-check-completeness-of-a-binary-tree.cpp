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
    int nodeCount(TreeNode* root) {
        if(root==NULL) return 0;
        return 1 + nodeCount(root->left) + nodeCount(root->right);
    }
    bool solve(TreeNode* root,int i,int total) {
        if(root==NULL) return true;
        if(i>=total) return false;
        else {
            bool left = solve(root->left,2*i+1,total);
            bool right = solve(root->right,2*i+2,total);
            return  left && right;
        }
    }
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;
        int i=0;
        int total = nodeCount(root);
        return solve(root,i,total);
    }
};