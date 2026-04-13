class Solution {
public:
    vector<vector<int>> res={};
    void generateSubsets(vector<int>& nums,vector<int>& temp,int i){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        generateSubsets(nums,temp,i+1);
        temp.pop_back();
        generateSubsets(nums,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ress={};
        generateSubsets(nums,ress,0);
        return res;
    }
};