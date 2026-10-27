class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int low=0;
        int high=nums.size()-k;

        while(low<high){
            int mid=low+(high-low)/2;

            if(abs(x-nums[mid])<=nums[mid+k]-x) high=mid;
            else low=mid+1;
        }
        vector<int> ans;
        for(int i=low;i<low+k;i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};