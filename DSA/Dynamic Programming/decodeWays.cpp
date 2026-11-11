class Solution {
public:
    unordered_map<string,int> map;
    int canBeDecoded(string remS){
        if(remS=="") return 1;

        if(remS[0]=='0') return 0;

        if(map.count(remS)) return map[remS];

        int ways=0;
        int n=remS.length();
        if(remS[n-1]!='0'){
            ways+=canBeDecoded(remS.substr(0,n-1));
        }

        if(n>=2){
            int num=stoi(remS.substr(n-2));
            if(num>=10 && num<=26){
                ways+=canBeDecoded(remS.substr(0,n-2));
            }

        }

        return map[remS]=ways;

    }
    int numDecodings(string s) {
        return canBeDecoded(s);
    }
};