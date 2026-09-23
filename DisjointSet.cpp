#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    
    vector<int> parent,rank;
    
    public:
        DisjointSet(int n){
            for(int i=0;i<=n;i++){
                rank.push_back(0);
                parent.push_back(i);
            }
        }
        
        int findUParent(int u){
            if(u==parent[u]) return u;
            
            return parent[u]=findUParent(parent[u]);
        }
        
        void unionByRank(int u,int v){
            int ulp_u=findUParent(u);
            int ulp_v=findUParent(v);
            if(ulp_u==ulp_v) return;
            
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;            
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
            }
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
};

int main() {
	// your code goes here
    DisjointSet ds(7);
    
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    cout<<ds.findUParent(7);
    ds.unionByRank(3,7);
    
    cout<<ds.findUParent(3);
}
