class Solution {
    void dfs(unordered_map<int, vector<int>>& graph, vector<int>& lowest, int parent, int node, vector<vector<int>>& res, int nextId) {
        // visited[node] = true;
        lowest[node] = nextId;
        nextId++;
        int curr = lowest[node];
        for(auto i: graph[node]) {
            if(i==parent) continue;
            if(lowest[i]==-1)
                dfs(graph, lowest, node, i, res, nextId);
            lowest[node] = min(lowest[node], lowest[i]);
            if(curr<lowest[i])
                res.push_back({node, i});
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> graph;
        for(auto v: connections) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<int> lowest(n, -1);
        vector<vector<int>> res;
        dfs(graph, lowest, -1, 0, res, 0);
        return res;
    }
};