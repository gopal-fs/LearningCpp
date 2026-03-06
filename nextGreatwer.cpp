class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> map;
        for(int num:nums2){
            while(!st.empty() && st.top()<num){
                map[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty()){
            map[st.top()]=-1;
            st.pop();
        }

        for(int i=0;i<nums1.size();i++) nums1[i]=map[nums1[i]];
        return nums1;
    }
};