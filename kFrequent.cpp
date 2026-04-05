class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
       unordered_map<int,int> map;
       for(int num:nums) map[num]++;
        vector<int> res;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(auto &mp:map){
            pq.push({mp.second,mp.first});
            if(pq.size()>k){
                pq.pop();
            }
        }

        while(k!=0){
            res.push_back(pq.top()[1]);
            pq.pop();
            k--;
        }
        return res;


    }
};