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
        void dfs(TreeNode* root, vector<int>& bv){
            if (root==NULL)return;
            if (root->left)dfs(root->left,bv);
            bv.push_back(root->val);
            if (root->right)dfs(root->right,bv);
        }
		
        int min1(vector<int>& bv, int val){
            int ans= -1;
            int i=0; int j= bv.size()-1;
            while (i<=j){
                int mid= i+ (j-i)/2;
                if (val== bv[mid])return val;
                if (val> bv[mid]){
                    ans= bv[mid];
                    i= mid+1;
                }
                else j= mid-1;
            }
            return ans;
        }
		
    int max1(vector<int>& bv,int val){
        int ans= -1;
        int i=0; int j= bv.size()-1;
        while (i<=j){
            int mid= i+ (j-i)/2;
            if (val== bv[mid])return val;
            if (val < bv[mid]){
                ans= bv[mid];
                j= mid-1;
            }
            else i= mid+1;
        }
        return ans;
    }
	
        vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> bv;
        vector<vector<int>> ans;
        dfs(root,bv);
        for (auto q: queries){
            int lb= min1(bv,q);
            int ub= max1(bv,q);
            ans.push_back({lb,ub});
        }
        return ans;
    }
    
};