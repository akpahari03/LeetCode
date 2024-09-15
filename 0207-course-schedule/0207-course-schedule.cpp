class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adjList(V);
        for(auto it:prerequisites) {
            adjList[it[0]].push_back(it[1]);
        }
        vector<int> inDegree(V,0);
        for(int i=0;i<V;i++) {
            for(auto it:adjList[i]) {
                inDegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(inDegree[i]==0) {
                q.push(i);
            }
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
        if(topo.size()==V) return true;
        return false;
    }
};