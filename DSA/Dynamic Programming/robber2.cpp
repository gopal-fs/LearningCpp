class Solution {
public:
    int getRob(vector<int> &nums,int start,int end){
        int n=nums.size();
        vector<int> dp(n,0);
        dp[start]=nums[start];
        dp[start+1]=max(nums[start],nums[start+1]);

        for(int i=2;i<=end;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }

        return dp[end];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(getRob(nums,0,n-2),getRob(nums,1,n-1));
    }
};