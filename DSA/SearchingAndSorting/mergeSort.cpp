class Solution {
public:
    void merge(vector<int> &nums,int low,int high,int mid){
        int i=low;
        int j=mid+1;
        int size=high-low+1;
        int temp[size];
        int k=0;

        while(i<=mid && j<=high){
            if(i<=mid && nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }

            else temp[k++]=nums[j++];
        }

        while(i<=mid) temp[k++]=nums[i++];
        while(j<=high) temp[k++]=nums[j++];

        for(int c=0;c<size;c++){
            nums[low+c]=temp[c];
        }
    }
    void merge_sort(vector<int> &nums,int low,int high){
        if(low>=high) return;

        int mid=low+(high-low)/2;
        merge_sort(nums,low,mid);
        merge_sort(nums,mid+1,high);
        merge(nums,low,high,mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums,0,nums.size()-1);
        return nums;
    }
};