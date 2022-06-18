class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        
        int n = nums.size();
        int sum=0;
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        
        if((s - target)%2 || abs(target)>s)return 0;
        
        sum = (s-target)/2;
        
        int t[n+1][sum+1];
        
        for(int i=0;i<n+1;i++){
            t[i][0] = 1;
        }
        for(int i=1;i<sum+1;i++){
            t[0][i] = 0;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(j >= nums[i-1]){
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};