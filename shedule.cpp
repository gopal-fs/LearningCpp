class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> visit(n,0);
        unordered_map<int,vector<int>> map;
        for(auto edge:prerequisites){
            map[edge[0]].push_back(edge[1]);
        }
        vector<int> indegree(n,0);
        
        queue<int> q;
        for(int i=0;i<n;i++){
            for(int num:map[i]){
                indegree[num]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> res;
        while(!q.empty()){
            int node=q.front(); q.pop();
            res.push_back(node);
            for(int num:map[node]){
                indegree[num]--;
                if(indegree[num]==0){
                    q.push(num);
                }
            }
            
        }
        
        
        
        return res.size()==n;
    }
};