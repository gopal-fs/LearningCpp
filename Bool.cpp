class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int count=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i<n-1 && s[i]==s[i+1]){
                dp[i][i+1]=1;
                count++;
            }
            count++;
        }

        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=1;
                    count++;
                }
            }
        }

        return count;
    }
};