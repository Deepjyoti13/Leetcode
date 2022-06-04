class Solution {
    
    bool DFS(vector<vector<int>>& adj, int src, vector<int>& visited) {
        visited[src]=1;
        for(int i: adj[src]) {
            if(visited[i]==1) return true;
            if(!visited[i])
                if(DFS(adj, i, visited)) return true;
        }
        visited[src]=2;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = prerequisites.size();
        if(!N) return true;
        vector<vector<int>> adj(numCourses);
        for(vector<int> prereq: prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
        }
        vector<int> visited(numCourses, 0);
        for(int i=0; i<numCourses; i++) {
            if(!visited[i]) {
                if(DFS(adj, i, visited))
                    return false;
            }
        }
        return true;
    }
};