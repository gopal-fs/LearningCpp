class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<int> dq;

        int i=0;
        int j=0;

        while(j<nums.size()){
            while(!dq.empty() && dq.back()<nums[j]) dq.pop_back();
            dq.push_back(nums[j]);
            if(j>=k-1){
                ans.push_back(dq.front());
                int val=nums[i];
                i++;
                if(val==dq.front()) dq.pop_front();
            }
            j++;
        }

        return ans;

    }
};