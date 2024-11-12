class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=queries.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({queries[i],i});
        }
        sort(v.begin(),v.end());
        sort(items.begin(),items.end());
        for(int i=1;i<items.size();i++){
            items[i][1]=max(items[i-1][1],items[i][1]);
        }
        vector<int>ans(n);
        int j=0,maxi=0;
        for(int i=0;i<n;i++){
            while(j<items.size() && items[j][0]<=v[i].first){
                maxi=max(maxi,items[j][1]);
                j++;
            }
            ans[v[i].second]=maxi;
        }
        return ans;
    }
};