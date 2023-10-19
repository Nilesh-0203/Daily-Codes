class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#' && st1.empty()){
                continue;
            }
            if(s[i]=='#' && !st1.empty()){
                st1.pop();
            }
            else{
                st1.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#' && st2.empty()){
                continue;
            }
            if(t[i]=='#' && !st2.empty()){
                st2.pop();
            }
            else{
                st2.push(t[i]);
            }
        }

        bool ans=false;
        if(st1.empty() && st2.empty()){
            return true;
        }
        if(st1.size()!=st2.size()){
            return false;
        }
        while(!st1.empty()){
            if(st1.top()==st2.top()){
                ans=true;
                st1.pop();
                st2.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        return ans;
    }
};