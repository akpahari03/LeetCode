class Solution {
public:
    struct TrieNode {
        TrieNode* left;
        TrieNode* right;
    };
    void insert(TrieNode* root, int& num) {
        TrieNode* pCrawl = root;
        for(int i=31;i>=0;i--) {
            int ith_bit = (num>>i) & 1;
            if(ith_bit==0) {
                if(pCrawl->left==NULL) pCrawl->left = new TrieNode();
                pCrawl = pCrawl->left;
            }
            else {
                if(pCrawl->right==NULL) pCrawl->right = new TrieNode();
                pCrawl = pCrawl->right;
            }
        }
    }
    
    int maxXor(TrieNode* root,int& num) {
        int maxi=0;
        TrieNode* pCrawl = root;
        for(int i=31;i>=0;i--) {
            int ith_bit = (num>>i) & 1;
            if(ith_bit==1) {
                if(pCrawl->left) {
                    maxi += pow(2,i);
                    pCrawl=pCrawl->left;
                } else {
                    pCrawl=pCrawl->right;
                }
            }
            else {
                if(pCrawl->right) {
                    maxi += pow(2,i);
                    pCrawl = pCrawl->right;
                } else {
                    pCrawl = pCrawl->left;
                }
            }
        }
        return maxi;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for(int &num : nums) {
            insert(root,num);
        }
        int ans=0;
        for(int &num : nums) {
            ans = max(ans,maxXor(root,num));
        }
        return ans;
    }
};