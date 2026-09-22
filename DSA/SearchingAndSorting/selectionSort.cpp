class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            int mini=i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[mini]) mini=j;
            }

            if(mini!=i){
                swap(nums[i],nums[mini]);
            }
        }

        return nums;
    }
};