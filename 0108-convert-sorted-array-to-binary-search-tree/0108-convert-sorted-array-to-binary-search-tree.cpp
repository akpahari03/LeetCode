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
    TreeNode* buildBST(vector<int>&nums,int s,int e) {
        if(s>e) return NULL;
        int mid=(s+e)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = buildBST(nums,s,mid-1);
        newNode->right = buildBST(nums,mid+1,e);
        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums,0,nums.size()-1);
    }
};