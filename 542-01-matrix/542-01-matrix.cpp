class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int M=mat.size(), N=mat[0].size();
        queue<vector<int>> q;
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(mat[i][j]==0) {
                    q.push(vector<int>{i,j});
                }
                else {
                    mat[i][j]=-1;
                }
            }
        }
        while(!q.empty()) {
            vector<int> cell = q.front();
            q.pop();
            int i=cell[0], j=cell[1];
            if(i+1<M && mat[i+1][j]==-1) {
                mat[i+1][j]=mat[i][j]+1;
                q.push(vector<int>{i+1, j});
            }
            if(i-1>=0 && mat[i-1][j]==-1) {
                mat[i-1][j]=mat[i][j]+1;
                q.push(vector<int>{i-1, j});
            }
            if(j+1<N && mat[i][j+1]==-1) {
                mat[i][j+1]=mat[i][j]+1;
                q.push(vector<int>{i, j+1});
            }
            if(j-1>=0 && mat[i][j-1]==-1) {
                mat[i][j-1]=mat[i][j]+1;
                q.push(vector<int>{i, j-1});
            }
        }
        return mat;
    }
};