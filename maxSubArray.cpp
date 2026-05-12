class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int currSum=0;

        for(int  num:nums){
            currSum=max(currSum+num,num);
            maxi=max(maxi,currSum);
        }

        return maxi;
    }
};