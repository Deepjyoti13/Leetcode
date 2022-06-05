class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int M=grid.size(), N=grid[0].size(), time=0;
        queue<pair<int, int>> q;
        bool isZero = false;;
        // vector<vector<bool>> visited(M+1, vector<bool>(N+1, false));
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j]==1) {
                    q.push(make_pair(i, j));
                }
                else isZero=true;
            }
        }
        if(!isZero) return -1;
        while(!q.empty()) {
            time++;
            int size=q.size();
            while(size--) {
                pair<int, int> p = q.front();
                q.pop();
                int i=p.first, j=p.second;
                // visited[i][j] = true;
                if(i+1<M && grid[i+1][j]!=1) {
                    q.push(make_pair(i+1, j));
                    grid[i+1][j]=1;
                }
                if(j+1<N && grid[i][j+1]!=1) {
                    q.push(make_pair(i, j+1));
                    grid[i][j+1]=1;
                }
                if(i-1>=0 && grid[i-1][j]!=1) {
                    q.push(make_pair(i-1, j));
                    grid[i-1][j]=1;
                }
                if(j-1>=0 && grid[i][j-1]!=1) {
                    q.push(make_pair(i, j-1));
                    grid[i][j-1]=1;
                }
            }
        }
        return time-1;
    }
};

    




