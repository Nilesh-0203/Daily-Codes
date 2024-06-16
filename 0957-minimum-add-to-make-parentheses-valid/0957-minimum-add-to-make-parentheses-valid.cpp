class Solution {
public:
    int minAddToMakeValid(string str) {
        stack<char>st;
        int cnt=0;
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(ch=='('){
              st.push(ch);
            }
            else{
             if(!st.empty() && st.top()=='('){
                st.pop();
             }
             else{
                st.push(ch);
             }
            }
        }
        cnt+=st.size();
        return cnt;
    }
};