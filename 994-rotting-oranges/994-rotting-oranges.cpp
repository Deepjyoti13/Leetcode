class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int M=grid.size(), N=grid[0].size(), time=0;
        queue<pair<int, int>> q;
        bool isTwo = false, isOne = false;;
        vector<vector<bool>> visited(M+1, vector<bool>(N+1, false));
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j]==2) {
                    q.push(make_pair(i, j));
                    isTwo = true;
                }
                else if(grid[i][j]==1) isOne = true;
            }
        }
        if(!isTwo && !isOne) return 0;
        while(!q.empty()) {
            time++;
            int size=q.size();
            while(size--) {
                pair<int, int> p = q.front();
                q.pop();
                int i=p.first, j=p.second;
                visited[i][j] = true;
                if(i+1<M && grid[i+1][j]==1 && !visited[i+1][j]) {
                    q.push(make_pair(i+1, j));
                    grid[i+1][j]=2;
                }
                if(j+1<N && grid[i][j+1]==1 && !visited[i][j+1]) {
                    q.push(make_pair(i, j+1));
                    grid[i][j+1]=2;
                }
                if(i-1>=0 && grid[i-1][j]==1 && !visited[i-1][j]) {
                    q.push(make_pair(i-1, j));
                    grid[i-1][j]=2;
                }
                if(j-1>=0 && grid[i][j-1]==1 && !visited[i][j-1]) {
                    q.push(make_pair(i, j-1));
                    grid[i][j-1]=2;
                }
            }
        }
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j]==1 && !visited[i][j])
                    return -1;
            }
        }
        return time-1;
    }
};


// x x
// o o
// . .
// x .