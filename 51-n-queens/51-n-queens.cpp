class Solution {
    
    bool isSafe(int col, int row, int N, vector<string>& ds) {
        int tCol=col, tRow=row;
        while(tRow>=0 && tCol>=0) {
            if(ds[tRow][tCol]=='Q') return false;
            tRow--; tCol--;
        }
        tCol=col, tRow=row;
        while(tCol>=0) {
            if(ds[tRow][tCol]=='Q') return false;
            tCol--;
        }
        tCol=col, tRow=row;
        while(tRow<N && tCol>=0) {
            if(ds[tRow][tCol]=='Q') return false;
            tRow++; tCol--;
        }
        return true;
    }
    
    void helper(int col, int N, vector<string>& ds, vector<vector<string>>& res) {
        if(col==N) {
            res.push_back(ds);
            return;
        }
        for(int row=0; row<N; row++) {
            if(isSafe(col, row, N, ds)) {
                ds[row][col] = 'Q';
                helper(col+1, N, ds, res);
                ds[row][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> ds(n);
        string s(n, '.');
        for(int i=0; i<n; i++) ds[i]=s;
        helper(0, n, ds, res);
        return res;
    }
};