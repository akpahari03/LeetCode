class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n==k) return true;
        if(n<k) return false;
        unordered_map<char,int> freq;
        for(char& ch : s) {
            freq[ch]++;
        }
        int oddFreq = 0;
        for(auto& i : freq) {
            if(i.second %2 != 0) {
                oddFreq++;
            }
        }
        if(oddFreq<=k)return true;
        return false;
    }
};