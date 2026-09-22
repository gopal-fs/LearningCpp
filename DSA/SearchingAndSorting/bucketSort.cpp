#include <bits/stdc++.h>
using namespace std;

void bucket_sort(vector<int> &nums){
    int maxi=*max_element(nums.begin(),nums.end());
    
    vector<vector<int>> temp(maxi+1);
    
    for(int num:nums) temp[num].push_back(num);
    
    int i=0;
    for(auto &bucket:temp){
        if(!bucket.empty()){
            for(int num:bucket) nums[i++]=num;
        }
    }
}
int main() {
	// your code goes here
	
	vector<int> nums = {4, 2, 7, 3, 2, 8, 3, 1, 6, 4};
	   
	   bucket_sort(nums);
	
	for(int num:nums) cout<<num<<" ";
	

}
