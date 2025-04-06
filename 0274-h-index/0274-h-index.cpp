class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> temp(n+1,0);
        for(auto c : citations) {
            if(c>n) temp[n]++;
            else temp[c]++;
        } 
        int count = 0;
        for(int i=n;i>=0;i--) {
            count += temp[i];
            if(count>=i) return i;
        }
        return 0;
    }
};