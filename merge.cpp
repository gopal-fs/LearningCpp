class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        res.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            vector<int> interval=nums[i];
            vector<int> newInterval=res[res.size()-1];

            if(interval[0]>newInterval[1]){
                res.push_back(interval);
            }
            else{
                
                newInterval[0]=min(newInterval[0],interval[0]);
                newInterval[1]=max(newInterval[1],interval[1]);
                res.pop_back();
                res.push_back(newInterval);
            }
        }
        return res;
    }
};