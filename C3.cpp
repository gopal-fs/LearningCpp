class Solution {
public:
    vector<vector<int>> ans;
    void findCombs(int start,int k,int n,int sum,vector<int> &temp){
        if(sum==n && temp.size()==k){
            ans.push_back(temp);
        }

        if(start>9) return;

        for(int i=start;i<10;i++){
            temp.push_back(i);
            findCombs(i+1,k,n,sum+i,temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> temp;
        findCombs(1,k,n,0,temp);
        return ans;
    }
};