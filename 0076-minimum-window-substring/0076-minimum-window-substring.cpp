class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int requiredCount = t.length();
        if(requiredCount>n) return "";

        unordered_map<char,int> mp;
        for(char &ch : t ) {
            mp[ch]++;
        }

        int i = 0;
        int j = 0;
        
        int start_i = 0;
        int minWindowSize = INT_MAX;

        while(j<n) {
            char ch = s[j];
            if(mp[ch]>0) {
                requiredCount--;
            }
            mp[ch]--;
            while(requiredCount==0) {
                int currWindowSize = j-i+1;
                if(currWindowSize < minWindowSize) {
                    minWindowSize = currWindowSize;
                    start_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) {
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        return minWindowSize == INT_MAX ? "" : s.substr(start_i,minWindowSize);
    }
};