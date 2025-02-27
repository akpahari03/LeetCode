class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<int> st;
        for(char& ch : jewels) {
            st.insert(ch);
        }
        int count = 0;
        for(char& s : stones) {
            if(st.find(s) != st.end()) count++;
        }
        return count;
    }
};