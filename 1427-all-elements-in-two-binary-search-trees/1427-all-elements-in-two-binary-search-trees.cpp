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
    vector<int> mergeArray(vector<int>& arr1,vector<int>& arr2) {
        vector<int> ans(arr1.size()+arr2.size());
        int i=0;
        int j=0;
        int k=0;
        while(i<arr1.size() && j<arr2.size()) {
            if(arr1[i]<=arr2[j]) ans[k++]=arr1[i++];
            else ans[k++]=arr2[j++];
        }
        while(i<arr1.size()) {
            ans[k++]=arr1[i++];
        }
        while(j<arr2.size()) {
            ans[k++]=arr2[j++];
        }
        return ans;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> in1;
        vector<int> in2;
        inorder(root1,in1);
        inorder(root2,in2);
        return mergeArray(in1,in2);
    }
};