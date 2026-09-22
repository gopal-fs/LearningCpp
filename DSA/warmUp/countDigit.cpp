#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countDigits(int n) {
        // Code here
        
        int count=0;
        
        while(n!=0){
            count++;
            n/=10;
        }
        return count;
    }
};

int main(){
    Solution s1;
    cout<<s1.countDigits(16);
}

/*
Time Complexity - O(N)
Space Complexity - O(1)
*/