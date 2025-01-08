class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                int len1 = words[i].length();
                int len2 = words[j].length();
                bool isPrefix = (len1<=len2) && (words[j].substr(0,len1)==words[i]);
                bool isSuffix = (len1<=len2) && (words[j].substr(len2-len1)==words[i]);
                if(isPrefix && isSuffix) count++;
            }
        }  
        return count; 
    }
};