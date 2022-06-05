class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> people(n, 0);
        vector<int> trustedPeople(n, 0);
        for(vector<int> v: trust) {
            people[v[0]-1]++;
            trustedPeople[v[1]-1]++;
        }
        for(int i=0; i<n; i++) {
            if(people[i]==0 && trustedPeople[i]==n-1)
                return i+1;
        }
        return -1;
    }
};