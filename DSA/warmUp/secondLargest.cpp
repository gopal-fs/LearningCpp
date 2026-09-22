#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> nums){
    
    int firstLargest=INT_MIN;
    int secondLargest=INT_MIN;
    
    for(int num:nums){
        if(num>firstLargest){
            secondLargest=firstLargest;
            firstLargest=num;
            
        }
        
        else if(num>secondLargest && num!=firstLargest) secondLargest=num;
    }
    return secondLargest;
}

int main() {
	// your code goes here
	vector<int> arr = {12, 45, 7, 23, 89, 34, 56};
	cout<<secondLargest(arr);

}


/*
Time Complexity - O(N)
Space Complexity - O(1)
*/