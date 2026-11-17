class Solution {
public:
    int coins=INT_MAX;
    unordered_map<int,int> map;
    int getCoins(vector<int>& coins, int amount) {
        if(amount==0) return 0;

        if(amount<=0) return INT_MAX;
        if(map.count(amount)) return map[amount];
        int miniCoins=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int res=getCoins(coins,amount-coins[i]);
            if(res!=INT_MAX) miniCoins=min(miniCoins,1+res);
        }

        return map[amount]=miniCoins;    
    }
    int coinChange(vector<int>& coins, int amount) {
        getCoins(coins,amount);
        return map[amount]==INT_MAX?-1:map[amount];


        
    }
};