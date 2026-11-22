class Solution {
public:
    
    bool func(vector<int> &nums, int k, int s){
        int sum=0,c=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>s){
                c++;
                sum=nums[i];
            }
        }
        return c<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        // largest sum of any subarray is minimised - 
        // find min that satisfies a condition (largest sum of k subarrays)
        // sum range is max of the nums array to sum of all elements in nums

        long long sum=0,mx=0;
        for(int i=0;i<nums.size();i++) {
            sum+= nums[i];
            mx=max(mx,nums[i]*1LL);
        }

        //binary search range - mx -> sum
        long long l=mx, r=sum;
        while(l<r){
            long long mid = (r+l)/2 ;
            if(func(nums,k,mid)){
                r=mid;
            } else{
                l=mid+1;
            }
        }

        return l;

    }
};