class Solution {
public:
    int bfs(int n,unordered_map<int,vector<int>>& adj) {
        queue<int> q;
        q.push(0);
        vector<bool> visited(n,false);
        visited[0] = true;

        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int node = q.front();
                q.pop();

                if(node==n-1) return level;

                for(int &temp : adj[node]) {
                    if(!visited[temp]) {
                        q.push(temp);
                        visited[temp] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++) {
            adj[i].push_back(i+1);
        }
        int k = queries.size();
        vector<int> result;
        for(auto& query : queries) {
            int u = query[0];
            int v = query[1];
            adj[u].push_back(v);
            int temp = bfs(n,adj);
            result.push_back(temp);
        }
        return result;

    }
};