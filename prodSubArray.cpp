class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ltr=1;
        int rtl=1;
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            ltr*=nums[i];
            rtl*=nums[n-i-1];
            maxi=max(maxi,max(ltr,rtl));
            if(rtl==0) rtl=1;
            if(ltr==0) ltr=1;

        }
        return maxi;
    }
};