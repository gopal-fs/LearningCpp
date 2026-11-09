class Solution {
public:
    unordered_map<int,bool> map;
    bool getJumps(vector<int>& nums,int start){
        if(start>=nums.size()-1) return true;

        if(nums[start]==0) return false;

        
        if(map.count(start)) return map[start];

        for(int i=1;i<=nums[start];i++){
            if(getJumps(nums,start+i)){
                return map[start]=true;
            };
        }

        return map[start]=false;
    }
    bool canJump(vector<int>& nums) {
        
        
        return getJumps(nums,0);

    }
};