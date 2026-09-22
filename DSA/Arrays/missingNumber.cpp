class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total=0;
        for(int num:nums) total+=num;
        int n=nums.size();
        int expected=(n*(n+1))/2;
        return expected-total;
    }
};