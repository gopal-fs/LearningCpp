#include <bits/stdc++.h>
using namespace std;

int sumOfAllNumbersInArr(vector<int> &nums,int i){
    
    if(i>=nums.size()) return 0;
    
    return nums[i]+sumOfAllNumbersInArr(nums,i+1);
    
    
}

int main() {
	// your code goes here
	
	vector<int> nums={1,2,3,4,5};
	cout<<sumOfAllNumbersInArr(nums,0)<<endl;

}
