class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
            // Code here
            vector<vector<vector<int>>> adj(V+1);

            for(int i=0; i<edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }

           
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
            vector<int> dist(V+1, 1e9);
            vector<int> memo(V+1, -1);
            dist[src] = 0;

          
            pq.push({dist[src], src});

            while(!pq.empty()){
               
                auto it = pq.top();
                int pathWt = it.first;
                int node = it.second;

               
                pq.pop();

                for(auto neighbour: adj[node]){
                    int adjNode = neighbour[0];
                    int adjWt = neighbour[1];

                    if(pathWt+adjWt < dist[adjNode]){
                        
                        dist[adjNode] = pathWt+adjWt;
                        
                        pq.push({dist[adjNode], adjNode});
                        memo[adjNode] = node;
                    } 

                }
            }
            vector<int> ans;
            if(dist[dest] == 1e9){
                return {-1};
            } else {
                int tmp = dest;
                while(tmp!=-1){
                    ans.push_back(tmp);
                    tmp = memo[tmp];
                }
                reverse(ans.begin(), ans.end());
                return ans;
            }
        }
};