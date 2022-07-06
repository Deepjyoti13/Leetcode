class Solution {
    class Node {
        public:
        string dest;
        double val;
        Node(string x, double y) {
            dest = x; val=y;
        }
    };
    unordered_map<string, vector<Node*>> buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        int N=values.size();
        unordered_map<string, vector<Node*>> adjList;
        for(int i=0; i<N; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            adjList[a].push_back(new Node(b, val));
            adjList[b].push_back(new Node(a, 1/val));
       }
        return adjList;
    }
    double dfs(unordered_map<string, vector<Node*>>& adjList, string& src, string& dest, set<string> seen) {
        if(!adjList.count(src) || !adjList.count(dest)) return -1.0;
        if(src == dest) return 1.00;
        seen.insert(src);
        int N = adjList[src].size();
        for(int i=0; i<N; i++) {
            string next = adjList[src][i]->dest;
            if(!seen.count(next)) {
                double data = adjList[src][i]->val;
                double res = dfs(adjList, next, dest, seen);
                if(res!=-1.0)
                    return res*data;   
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<Node*>> adjList = buildGraph(equations, values);
        int N = queries.size();
        vector<double> res(N, -1.0);
        for(int i=0; i<N; i++) {
            string src = queries[i][0];
            string dest = queries[i][1];
            double ans = dfs(adjList, src, dest, set<string>());
            res[i] = ans;
        }
        return res;
    }
};