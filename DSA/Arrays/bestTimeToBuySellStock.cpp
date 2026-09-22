class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxi=0;
        int mini=nums[0];

        for(int num:nums){
            mini=min(mini,num);
            maxi=max(maxi,num-mini);
        }
        return maxi;
    }
};