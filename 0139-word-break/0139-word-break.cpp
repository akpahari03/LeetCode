class TrieNode {
    public:
    char data;
    TrieNode* child[26];
    bool isTerminal;
    TrieNode(char ch) {
        data = ch;
        for(int i=0;i<26;i++) {
            child[i]=NULL;
        }
        isTerminal = false;
    }
};
void insert(string s , TrieNode* root) {
    TrieNode* temp = root;
    for(int i=0;i<s.length();i++) {
        int index = s[i]-'a';
        if(temp->child[index]==NULL) {
            temp->child[index] = new TrieNode(s[i]);
        }
        temp = temp->child[index];
    }
    temp->isTerminal = true;
}
bool search(string &s, TrieNode* root, int start, int end) {
    TrieNode* temp = root;
    for (int i = start; i <= end; i++) {
        int index = s[i] - 'a';
        if (temp->child[index] == NULL) {
            return false;
        }
        temp = temp->child[index];
    }
    return temp->isTerminal;
}
bool breakWordUntil(string &s, TrieNode* root, int start, vector<int>& memo) {
    if (start == s.length()) return true;
    if (memo[start] != -1) return memo[start];
    for (int end = start; end < s.length(); end++) {
        if (search(s, root, start, end) && breakWordUntil(s, root, end + 1, memo)) {
            return memo[start] = true;
        }
    }
    return memo[start] = false;
}
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode('\0');
        for(int i=0;i<wordDict.size();i++) {
            insert(wordDict[i],root);
        }
        // Memoization array, initialized with -1 (unknown)
        vector<int> memo(s.length(), -1);
        return breakWordUntil(s,root,0,memo);
    }
};