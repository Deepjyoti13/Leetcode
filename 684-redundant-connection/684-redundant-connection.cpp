class Solution {
    int findParent(int i, vector<int>& parent) {
        if(parent[i]==-1) return i;
        return parent[i] = findParent(parent[i], parent);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1, -1);
        for(vector<int> v: edges) {
            int parentV0 = findParent(v[0], parent);
            int parentV1 = findParent(v[1], parent);
            if(parentV0==parentV1) return v;
            parent[parentV0] = parentV1;
        }
        return vector<int>();
    }
};