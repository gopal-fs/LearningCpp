class Solution {
public:
    int maxi = 1;
    int findLIS(vector<int>& nums,vector<int>& dp) {
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1); 
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        return findLIS(nums,dp);
        
    }
};