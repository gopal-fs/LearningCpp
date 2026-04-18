class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool isPush=false;
        for(int i=0;i<intervals.size();i++){
            vector<int> temp=intervals[i];

            //Before Interval
            if(temp[1]<newInterval[0]){
                res.push_back(temp);
            } 

            //After Interval 
            else if(temp[0]>newInterval[1]){
                if(!isPush){
                    isPush=true;
                    res.push_back(newInterval);
                    res.push_back(intervals[i]);
                }
                else res.push_back(intervals[i]);
            }

            //Overlap
            else{
                newInterval[0]=min(newInterval[0],temp[0]);
                newInterval[1]=max(newInterval[1],temp[1]);
            }
        }

        if(!isPush) res.push_back(newInterval);

        return res;
    }
};