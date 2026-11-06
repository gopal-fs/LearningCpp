class Solution {
public:
    void permutations(vector<int>& nums,vector<int> &temp,vector<vector<int>> &res,vector<int> &visit,int n){
        
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }


        for(int i=0;i<n;i++){
           
            if(visit[i]) continue;
            temp.push_back(nums[i]);
            visit[i]=1;
            permutations(nums,temp,res,visit,n);
            visit[i]=0;
            temp.pop_back();

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> visit(nums.size(),0);
        permutations(nums,temp,res,visit,nums.size());
        return res;
    }
};