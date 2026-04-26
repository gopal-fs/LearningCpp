class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1,INT_MAX-1);
        dp[0]=0;
        int n=coins.size();
        for(int rem=1;rem<=amount;rem++){
            for(int j=0;j<n;j++){
                int remAmount=rem-coins[j];
                if(remAmount>=0){
                    dp[rem]=min(dp[rem],1+dp[remAmount]);
                }
            }
        }
        return dp[amount]==INT_MAX-1?-1:dp[amount];
    }
};