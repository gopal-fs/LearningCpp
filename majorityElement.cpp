class Solution {
public:
    int majorityElement(vector<int>& nums) {

        map<int,int> hashmap={};

        for(int i=0;i<nums.size();i++){
            hashmap[nums[i]]++;
        }

        for(auto &map:hashmap){
            if(map.second>(nums.size()/2)) return map.first;
        }
        
        return 0;
    }
};