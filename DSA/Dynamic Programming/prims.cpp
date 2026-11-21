class Solution {
  public:
    int primMST(vector<vector<vector<int>>> &edges) {
        // code here
        unordered_map<int,vector<pair<int,int>>> map;
        int V=0;
        for(auto &part:edges){
            for(auto edge:part){
                map[V].push_back({edge[0],edge[1]});
            }
            V++;
        }
        
        vector<int> visit(V,0);
        int sum=0;
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        
        pq.push({0,{0,-1}});
        
        vector<int> path;
        
        while(!pq.empty()){
            auto it=pq.top(); pq.pop();
            int wt=it.first;
            int node=it.second.first;
            int parent=it.second.second;
            if(visit[node]) continue;
            visit[node]=1;
            sum+=wt;
            path.push_back(node);
            for(auto &edge : map[node]){
                int adjNode = edge.first;
                int adjWt = edge.second;

                if(!visit[adjNode]){
                    pq.push({adjWt,{adjNode,node}});
                }
            }
        }
        
        return sum;
    }
};