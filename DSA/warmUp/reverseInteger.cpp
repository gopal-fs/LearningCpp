#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        
        while(x!=0){
            rev=(long long)(rev*10)+x%10;
            x/=10;
        }

        if(rev<pow(-2,31) || rev>pow(2,31)-1) return 0;
        return rev;
    }
};


int main(){
    Solution s1;
    int res=s1.reverse(123);
    if(res==0) cout<<"Reversing a Number can Cause Overflow"<<endl;
    else cout<<res<<endl;
}

/*
Time Complexity - O(N)
Space Complexity - O(1)
*/