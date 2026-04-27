class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();

        vector<vector<int>> dp(n,vector<int>(n,-1));
        int count=0;
        int maxi[2]={0,0};

        //Base Case for 1 Length and 2 Length Palindromes
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i<n-1 && s[i]==s[i+1]){
                dp[i][i+1]=1;
                count++;
                if(i+1-i>(maxi[1]-maxi[0])){
                    maxi[0]=i;
                    maxi[1]=i+1;
                }
            }
            
            count++;
        }

        //3 ...n Length
       
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    count++;
                    if(j-i>(maxi[1]-maxi[0])){
                        maxi[0]=i;
                        maxi[1]=j;
                    }
                }
            }
        }

        
        string res=s.substr(maxi[0],maxi[1]-maxi[0]+1);
        return res;
    }
};