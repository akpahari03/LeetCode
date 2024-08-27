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
    int getDepthLeft(TreeNode* root) {
        int depth = 0;
        while (root != NULL) {
            depth++;
            root = root->left;
        }
        return depth;
    }
    int getDepthRight(TreeNode* root) {
        int depth=0;
        while(root!=NULL) {
            depth++;
            root=root->right;
        }
        return depth;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int leftDepth = getDepthLeft(root);
        int rightDepth = getDepthRight(root);

        if(leftDepth==rightDepth) return pow(2,leftDepth)-1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};