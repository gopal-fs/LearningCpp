class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            bool isSwap=false;
            for(int j=0;j<nums.size()-1;j++){
                if(nums[j]>nums[j+1]){
                    isSwap=true;
                    swap(nums[j],nums[j+1]);
                }
            }
            if(!isSwap) return nums;
        }
        return
    }
};