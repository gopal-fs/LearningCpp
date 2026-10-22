class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string res="";
        for(char c:s){
            if(c=='('){
                st.push(c);
                if(st.size()>1) res+=c;
            }
            else{
                st.pop();
                if(st.size()>0) res+=c;
            }
        }
        return res;

    }
};