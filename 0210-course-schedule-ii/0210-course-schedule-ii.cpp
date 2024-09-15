class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adjList(n);  //same as vector<int> adjList[n] (n must be initilized at complile time)
        for(auto it:prerequisites) {
            adjList[it[1]].push_back(it[0]);
        }
        vector<int> inDegree(n,0);
        for(int i=0;i<n;i++) {
            for(auto it:adjList[i]) {
                inDegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(inDegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adjList[node]) {
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }
        if(topo.size()==n) return topo;
        else return {};
    }
};