class Solution {
    
    vector<vector<int>> buildGraph(int N, vector<vector<int>>& values) {
        vector<vector<int>> adjList(N);
        for(vector<int> i: values) {
            adjList[i[1]].push_back(i[0]);
        }
        return adjList;
    }
    
    bool DFS(vector<vector<int>>& grid, int sv, int N, vector<int>& visited, vector<int>& order) {
        visited[sv]=1;
        for(int i: grid[sv]) {
            if(visited[i]==1) return true;
            if(!visited[i])
                if(DFS(grid, i, N, visited, order)) return true;
        }
        visited[sv]=2;
        order.push_back(sv);
        return false;
    }
public:
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {                         vector<vector<int>> grid = buildGraph(numCourses, prerequisites);    
        vector<int> visited(numCourses, 0);

        vector<int> order;
        for(int i=0; i<numCourses; i++) {
            if(!visited[i]) {
                if(DFS(grid, i, numCourses, visited, order))
                    return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};