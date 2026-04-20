class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> ans(1001,0);

     

        for(int i=0;i<trips.size();i++){
            vector<int> temp=trips[i];
            ans[temp[1]]+=temp[0];
            ans[temp[2]]-=temp[0];
        }
        
        int used=0;
        for(int num:ans){
            used+=num;
            if(used>capacity) return false;
        }
        return true;


    }
};