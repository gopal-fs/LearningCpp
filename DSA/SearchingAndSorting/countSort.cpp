#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &nums){
    int maxi=*max_element(nums.begin(),nums.end());
    
    vector<int> temp(maxi+1,0);
    
    for(int num:nums) temp[num]++;
    
    int i=0;
    int j=0;
    
    while(j<=maxi){
        if(temp[j]>0){
            nums[i++]=j;
            temp[j]--;
        }
        else j++;
    }
}
int main() {
	// your code goes here
	
	vector<int> nums = {4, 2, 7, 3, 2, 8, 3, 1, 6, 4};
	   
	   count_sort(nums);
	
	for(int num:nums) cout<<num<<" ";
	

}
