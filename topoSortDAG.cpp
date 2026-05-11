#include <bits/stdc++.h>
using namespace std;

vector<int> res;

void topologicalSort(int v,unordered_map<int,vector<int>> &map){
    vector<int> indegree(v,0);
    
    
    //Create An Indegree Array -O(N+E)
    for(auto &mp:map){
        for(int num:mp.second){
            indegree[num]++;
        }
    }
    
    
    //Push All 0 Elements to queue
    queue<int> q;
    
    
    // - O(N)
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0) q.push(i);
    }
    
    
    //O(N+E)
    while(!q.empty()){
        int curr=q.front(); q.pop();
        res.push_back(curr);
        for(int num:map[curr]){
            indegree[num]--;
            if(indegree[num]==0){
                q.push(num);
            }
        }
    }
}

int main() {
	// your code goes here
	int v=6;
	unordered_map<int,vector<int>> map={
	    {0,{}},
	    {1,{}},
	    {2,{3}},
	    {3,{1}},
	    {4,{0,1}},
	    {5,{0,2}}
	};
	
	topologicalSort(v,map);
	
	if(res.size()!=v){
	    cout<<"Topological Sort Cannot be performed";
	}
	else{
	    for(int num:res){
	        cout<<num<<" ";
	    }
	}
	
	

}
