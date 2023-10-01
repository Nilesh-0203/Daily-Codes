class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
               reverse(s.begin()+j,s.begin()+i);
               j=i+1;
            }
            if(i==s.length()-1){
                i=s.length();
                reverse(s.begin()+j,s.begin()+i);
            }
        }
        return s;
    }
};