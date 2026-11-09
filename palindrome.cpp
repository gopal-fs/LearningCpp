class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string s){
        int i=0;
        int j=s.length()-1;

        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void canPartition(string s,vector<string> &temp,string remS){
        if(remS.length()==0){
            res.push_back(temp);
            return;
        };
        for(int i=1;i<=remS.length();i++){
            string word=remS.substr(0,i);
            if(!isPalindrome(word)) continue;
            temp.push_back(word);
            canPartition(s,temp,remS.substr(i));
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        
        
        vector<string> temp;
        canPartition(s,temp,s);
        return res;
    }
};