#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        long long rev=0;
        int copy=x;

        while(x!=0){
            rev=(long long)(rev*10)+x%10;
            x/=10;
        }
        return rev==copy;
    }
};

int main(){
    Solution s1;
    if(s1.isPalindrome(121)) cout<<"Palindrome Number"<<endl;
    else cout<<"Not a Palindrome Number"<<endl;
}

/*
Time Complexity - O(N)
Space Complexity - O(1)
*/