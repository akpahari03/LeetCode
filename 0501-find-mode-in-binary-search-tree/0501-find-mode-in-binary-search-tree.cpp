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
    int currNum=0;
    int currFreq=0;
    int maxFreq=0;
    void inorder(TreeNode* root,vector<int>& ans) {
        if(root==NULL) return;
        inorder(root->left,ans);

        if(root->val==currNum) {
            currFreq++;
        } else {
            currNum=root->val;
            currFreq=1;
        }
        if(currFreq>maxFreq) {
            ans={};
            maxFreq=currFreq;
        }
        if(currFreq==maxFreq) {
            ans.push_back(root->val);
        }

        inorder(root->right,ans);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};