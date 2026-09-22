class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums[index]){
                swap(nums[i],nums[++index]);
            }
        }
        return ++index;
    }
};