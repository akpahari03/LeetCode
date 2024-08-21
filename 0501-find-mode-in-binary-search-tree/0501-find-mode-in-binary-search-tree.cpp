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
    void inorder(TreeNode* root,unordered_map<int,int>& mp) {
        if(root==NULL) return;
        inorder(root->left,mp);
        mp[root->val]++;
        inorder(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        inorder(root,mp);
        vector<int> ans;
        int maxFreq=0;
        for(auto& it:mp) {
            if(it.second>maxFreq) {
                maxFreq=it.second;
                ans={};
                ans.push_back(it.first);
            } else if(it.second==maxFreq) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};