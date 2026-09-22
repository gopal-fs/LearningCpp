#include <bits/stdc++.h>
using namespace std;

void change_arr(vector<int> &nums,vector<vector<int>> &temp){
    
    int i=0;
    for(auto &bucket:temp){
        if(!bucket.empty()){
            for(int num:bucket){
                nums[i++]=num;
            }
        }
        bucket.clear();
    }
}

void radix_sort(vector<int> &nums){
    int maxi=*max_element(nums.begin(),nums.end());
    
    vector<vector<int>> temp(10);
    long long rev=1;
    
    while(maxi/rev>0){
        
        for(int num:nums){
            temp[(num/rev)%10].push_back(num);
        }
        
        
        change_arr(nums,temp);
        
        rev*=10;
    }
}
int main() {
	// your code goes here
	
	vector<int> nums = {170, 45, 75, 90, 802, 24, 2, 66};
	   
	radix_sort(nums);
	
	for(int num:nums) cout<<num<<" ";
	

}
