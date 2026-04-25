class Solution {
public:
    
    unordered_map<int,long long> map;
    long long findMinimumCoins(vector<int>& coins,int amount){

        if(amount==0) return 0;
        if(amount<0) return LLONG_MAX;

        if(map.count(amount)==1) return map[amount];
        long long miniCoins=LLONG_MAX;

        for(int i=0;i<coins.size();i++){
            long long res=findMinimumCoins(coins,amount-coins[i]);
            if(res!=LLONG_MAX) miniCoins=min(miniCoins,(long long)1+res);
        }
        return map[amount]=miniCoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        
        long long res=findMinimumCoins(coins,amount);
        return res==LLONG_MAX?-1:res;


    }
};