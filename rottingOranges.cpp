class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<vector<int>> q1;
        //Filling queue with rotten oranges
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2) q1.push({i,j,0});
            }
        }

        int minutes=0;
        while(!q1.empty()){
            vector<int> curr=q1.front(); q1.pop();
            int x=curr[0];
            int y=curr[1];
            int mins=curr[2];
            if(x>0 && grid[x-1][y]==1){
                grid[x-1][y]=2;
                q1.push({x-1,y,mins+1});
            }
            if(x<rows-1 && grid[x+1][y]==1){
                grid[x+1][y]=2;
                q1.push({x+1,y,mins+1});
            }
            if(y>0 && grid[x][y-1]==1){
                grid[x][y-1]=2;
                q1.push({x,y-1,mins+1});
            }
            if(y<cols-1 && grid[x][y+1]==1){
                grid[x][y+1]=2;
                q1.push({x,y+1,mins+1});
            }
            minutes=max(minutes,mins);

        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return minutes;


        
    }
};