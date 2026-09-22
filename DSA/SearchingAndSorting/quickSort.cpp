class Solution {
public:
    int partition(vector<int> &nums,int low,int high){
        int pivot=low;
        int i=low;
        int j=high;

        while(i<=j){
            while(i<=j && nums[i]<=nums[pivot]) i++;
            while(i<=j && nums[j]>=nums[pivot]) j--;

            if(i<j){
                swap(nums[i],nums[j]);
            }
        }

        swap(nums[j],nums[pivot]);
        return j;
    }
    void quick_sort(vector<int> &nums,int low,int high){
        if(low>=high) return;

        int j=partition(nums,low,high);
        quick_sort(nums,low,j-1);
        quick_sort(nums,j+1,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums,0,nums.size()-1);
        return nums;
    }
};