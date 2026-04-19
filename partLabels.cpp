class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> first(26,-1);
        vector<int> last(26,-1);

        for(int i=0;i<s.length();i++){
            if(first[s[i]-'a']<0){
                first[s[i]-'a']=i;
            }
            last[s[i]-'a']=i;
        }

        vector<int> res;
        int partStart=0;
        int partEnd=0;
        for(int i=0;i<s.length();i++){
            if(partEnd<first[s[i]-'a']){
                res.push_back(partEnd-partStart+1);
                partStart=i;
                partEnd=i;   
            }
            partEnd=max(partEnd,last[s[i]-'a']);
        }

        if(partEnd-partStart+1>0) res.push_back(partEnd-partStart+1);
        return res;

    }
};