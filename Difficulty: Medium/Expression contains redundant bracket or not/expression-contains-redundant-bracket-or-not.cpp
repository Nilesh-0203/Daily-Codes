class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char>a;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                int c=0;
                while(!a.empty() && a.top()!='(')
                { if(a.top()=='+' || a.top()=='-' ||a.top()=='*' || a.top()=='/')
                c++;
                    a.pop();
                }
                if(c<1){
                    return true;
                }
                a.pop();
            } else{
                a.push(s[i]);
            }
        }
        return false;
    }
};
