class Solution {
public:
    void dfs(vector<vector<int>>& map,vector<vector<int>>& res,vector<int> &temp,int src,int dest){
        temp.push_back(src);
        if(src==dest){
            res.push_back(temp);
            return;
        }
        for(int num:map[src]){
            dfs(map,res,temp,num,dest);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> temp;
        int n=graph.size();
        dfs(graph,res,temp,0,n-1);
        return res;
    }
};