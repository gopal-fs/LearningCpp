class Solution {
public:
    void bfs(int row,int col,vector<vector<int>> &visit,vector<vector<char>>& grid){
        visit[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                
                    int nrow=row+dr[i];
                    int ncol=col+dc[i];
                    if(nrow<grid.size() && nrow>=0 && ncol<grid[0].size() && ncol>=0 && grid[nrow][ncol]=='1' && !visit[nrow][ncol]){
                        visit[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                    
                
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
       
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
        vector<vector<int>> visit(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visit[i][j] && grid[i][j]=='1'){
                    count++;
                    
                    bfs(i,j,visit,grid);
                }
            }
        }
        return  count;
    }
};