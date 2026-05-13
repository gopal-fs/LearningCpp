class Solution {
public:
    int trap(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int leftMax=0;
        int rightMax=0;
        int water=0;

        while(left<right){
            if(nums[left]<nums[right]){
                leftMax=max(leftMax,nums[left]);
                water+=leftMax-nums[left];
                left++;
            }
            else{
                rightMax=max(rightMax,nums[right]);
                water+=rightMax-nums[right];
                right--;
            }
        }
        return water;

    }
};