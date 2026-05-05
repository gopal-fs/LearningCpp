class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<int>> dist(rows,vector<int>(cols,1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        dist[0][0]=0;
        //{Diff,Row,Col};
        pq.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==rows-1 && col==cols-1) return diff;
            for(int i=0;i<4;i++){
                int newR=row+dr[i];
                int newC=col+dc[i];
                
                if(newR>=0 && newC>=0 && newR<rows && newC<cols){
                    int newEffort=max(abs(heights[row][col]-heights[newR][newC]),diff);
                    if(newEffort<dist[newR][newC]){
                        dist[newR][newC]=newEffort;
                        pq.push({newEffort,{newR,newC}});
                    }
               }
            }
        }
        return 0;

    }
};