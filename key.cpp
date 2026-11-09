class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> map;
        for(string s:strs){
            int n=s.length();

            vector<int> freq(26);

            for(char c:s){
                freq[c-'a']++;
            }

            string key="";
            for(int num:freq){
                key+='#'+to_string(num);
            }

            map[key].push_back(s);
        }

        vector<vector<string>> res;
        for(auto &mp:map) res.push_back(mp.second);
        return res;

    }
};