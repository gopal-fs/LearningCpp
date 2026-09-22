class Solution {
public:
    bool isPowerOfThree(int n) {
        long long num=3486784401;

        return n>0 && num%n==0;
    }
};