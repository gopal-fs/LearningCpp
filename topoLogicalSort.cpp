#include <bits/stdc++.h>
using namespace std;
vector<int> res;

void dfs(int start,vector<int> &visit,unordered_map<int,vector<int>> &map){
    visit[start]=1;
    
    for(int num:map[start]){
        if(!visit[num]){
            dfs(num,visit,map);
        }
    }
    res.push_back(start);
}

void topologicalSort(unordered_map<int,vector<int>> &map,int v){
    vector<int> visit(v,0);
    for(int i=0;i<v;i++){
        if(!visit[i]){
            dfs(i,visit,map);
        }
        
    }
}

int main() {
	// your code goes here
	
	unordered_map<int,vector<int>> map={
	    {0,{}},
	    {1,{}},
	    {2,{3}},
	    {3,{1}},
	    {4,{0,1}},
	    {5,{0,2}}
	};
	int v=6;
	
	topologicalSort(map,v);
	std::reverse(res.begin(), res.end());
	for(int num:res) cout<<num<<" ";
	
	

}
