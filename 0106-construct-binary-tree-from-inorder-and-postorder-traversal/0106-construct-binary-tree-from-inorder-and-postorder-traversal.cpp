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
    void createMapping(vector<int>& inorder,map<int,int>& nodeToIndex,int n) {
        for(int i=0;i<n;i++) {
            nodeToIndex[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int& index,int inorderStart,int inorderEnd,int n,map<int,int>& nodeToIndex) {
        //base case
        if(index < 0 || inorderStart>inorderEnd) return NULL;

        int element=postorder[index--];
        TreeNode* root= new TreeNode(element);
        int position = nodeToIndex[element]; 

        root->right = solve(postorder,inorder,index,position+1,inorderEnd,n,nodeToIndex);
        root->left = solve(postorder,inorder,index,inorderStart,position-1,n,nodeToIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postorderIndex=n-1;
        map<int,int> nodeToIndex;
        createMapping(inorder,nodeToIndex,n);

        TreeNode* ans = solve(postorder,inorder,postorderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};