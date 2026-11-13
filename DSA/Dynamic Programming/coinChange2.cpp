class Solution {
public:
    
    int getCombs(vector<int>& coins,int amount,int start,vector<vector<int>> &dp){

       
        if(amount==0){
            return 1;
        }
        if(amount<0) return 0;

        if(dp[start][amount]!=-1) return dp[start][amount];

        int ways=0;
        for(int i=start;i<coins.size();i++){
            ways+=getCombs(coins,amount-coins[i],i,dp);
        }

        return dp[start][amount]=ways;

        
    }
    int change(int amount, vector<int>& coins) {

        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return getCombs(coins,amount,0,dp);
        
    }
};