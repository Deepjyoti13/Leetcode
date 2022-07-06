class Solution {
    bool checkBipartite(vector<vector<int>>& grid, int src, int N, vector<int>& visited)     {
        queue<int> q;
        q.push(src);
        visited[src]=0;
        vector<bool> seen(N, false);
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            seen[front]=true;
            for(int i: grid[front]) {
                if(visited[i]==-1) {
                    visited[i]=visited[front]+1;
                    q.push(i);
                }
                else {
                    if(!seen[i] && visited[i]!=visited[front]+1)
                        return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> visited(N, -1);
        for(int i=0; i<N; i++) {
            if(visited[i]==-1) {
                if(!checkBipartite(graph, i, N, visited)) return false;
            }
        }
        return true;
    }
};